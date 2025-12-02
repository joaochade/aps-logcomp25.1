#!/usr/bin/env python3
"""
CoffeeVM - Interpretador para Assembly da Máquina de Café
Executa código assembly gerado pelo compilador CoffeeLang
"""

import sys
import time
import re

class CoffeeVM:
    def __init__(self):
        # Registradores (R0, R1, R2, R3)
        self.registers = {'R0': 0, 'R1': 0, 'R2': 0, 'R3': 0}
        
        # Memória (256 posições)
        self.memory = [0] * 256
        
        # Variáveis nomeadas
        self.variables = {}
        
        # Sensores (readonly)
        self.sensors = {
            'COIN_INSERTED': 3,      # Número de moedas inseridas
            'WATER_LEVEL': 100,      # 0-100%
            'BEANS_LEVEL': 80,       # 0-100%
            'CUP_PRESENT': 1,        # 1 = copo presente
            'CURRENT_TEMP': 25,      # temperatura em °C
            'EMERGENCY': 0           # 0 = normal, 1 = emergência
        }
        
        # Atuadores (hardware simulado)
        self.actuators = {
            'GRINDER': 0,
            'HEATER': 0,
            'PUMP': 0,
            'VALVE_WATER': 0,
            'VALVE_COFFEE': 0,
            'VALVE_STEAM': 0,
            'VALVE_MILK': 0,
            'DISPLAY': ""
        }
        
        # Flags de comparação
        self.zero_flag = False
        self.negative_flag = False
        
        # Program counter e labels
        self.pc = 0
        self.labels = {}
        self.instructions = []
        
        # Call stack para rotinas
        self.call_stack = []
        
        # Controle de execução
        self.running = True
        self.verbose = True
    
    def load_program(self, filename):
        """Carrega programa assembly do arquivo"""
        with open(filename, 'r') as f:
            lines = f.readlines()
        
        # Primeira passada: encontrar labels
        for i, line in enumerate(lines):
            line = line.strip()
            
            # Ignorar comentários e linhas vazias
            if not line or line.startswith(';'):
                continue
            
            # Remover comentários inline
            if ';' in line:
                line = line.split(';')[0].strip()
            
            # Detectar labels (formato: "label:")
            if line.endswith(':'):
                label_name = line[:-1]
                self.labels[label_name] = len(self.instructions)
            else:
                self.instructions.append(line)
        
        if self.verbose:
            print(f"✓ Programa carregado: {len(self.instructions)} instruções")
            print(f"✓ Labels encontrados: {list(self.labels.keys())}\n")
    
    def execute(self):
        """Executa o programa"""
        print("=" * 60)
        print("🚀 INICIANDO COFFEEVM")
        print("=" * 60)
        print()
        
        while self.running and self.pc < len(self.instructions):
            instruction = self.instructions[self.pc]
            
            if self.verbose:
                print(f"[PC={self.pc:3d}] {instruction}")
            
            self.execute_instruction(instruction)
            self.pc += 1
        
        print("\n" + "=" * 60)
        print("✓ EXECUÇÃO FINALIZADA")
        print("=" * 60)
        self.print_state()
    
    def execute_instruction(self, instruction):
        """Executa uma única instrução"""
        parts = instruction.split()
        if not parts:
            return
        
        cmd = parts[0]
        
        # Instruções de manipulação de registradores
        if cmd == 'SET':
            reg = parts[1]
            value = self.get_value(parts[2])
            self.registers[reg] = value
        
        elif cmd == 'LOAD':
            reg = parts[1]
            var = parts[2]
            if var in self.variables:
                self.registers[reg] = self.variables[var]
            else:
                self.registers[reg] = 0
        
        elif cmd == 'STORE':
            reg = parts[1]
            var = parts[2]
            self.variables[var] = self.registers[reg]
        
        # Operações aritméticas
        elif cmd == 'ADD':
            if len(parts) == 3:
                reg1 = parts[1]
                reg2 = parts[2]
                self.registers[reg1] += self.registers[reg2]
            else:
                reg = parts[1]
                value = self.get_value(parts[2])
                self.registers[reg] += value
        
        elif cmd == 'SUB':
            reg1 = parts[1]
            reg2 = parts[2]
            self.registers[reg1] -= self.registers[reg2]
        
        elif cmd == 'MUL':
            reg1 = parts[1]
            reg2 = parts[2]
            self.registers[reg1] *= self.registers[reg2]
        
        elif cmd == 'DIV':
            reg1 = parts[1]
            reg2 = parts[2]
            if self.registers[reg2] != 0:
                self.registers[reg1] //= self.registers[reg2]
        
        elif cmd == 'MOD':
            reg1 = parts[1]
            reg2 = parts[2]
            if self.registers[reg2] != 0:
                self.registers[reg1] %= self.registers[reg2]
        
        elif cmd == 'NEG':
            reg = parts[1]
            self.registers[reg] = -self.registers[reg]
        
        # Operações lógicas
        elif cmd == 'AND':
            reg1 = parts[1]
            reg2 = parts[2]
            self.registers[reg1] = int(self.registers[reg1] and self.registers[reg2])
        
        elif cmd == 'OR':
            reg1 = parts[1]
            reg2 = parts[2]
            self.registers[reg1] = int(self.registers[reg1] or self.registers[reg2])
        
        elif cmd == 'NOT':
            reg = parts[1]
            self.registers[reg] = int(not self.registers[reg])
        
        # Comparação
        elif cmd == 'CMP':
            reg1 = parts[1]
            reg2 = parts[2]
            result = self.registers[reg1] - self.registers[reg2]
            self.zero_flag = (result == 0)
            self.negative_flag = (result < 0)
        
        # Saltos
        elif cmd == 'JMP':
            label = parts[1]
            self.pc = self.labels[label] - 1  # -1 porque o PC será incrementado
        
        elif cmd == 'JZ':
            reg = parts[1]
            label = parts[2]
            if self.registers[reg] == 0:
                self.pc = self.labels[label] - 1
        
        elif cmd == 'JE':
            if self.zero_flag:
                self.pc = self.labels[parts[1]] - 1
        
        elif cmd == 'JNE':
            if not self.zero_flag:
                self.pc = self.labels[parts[1]] - 1
        
        elif cmd == 'JL':
            if self.negative_flag:
                self.pc = self.labels[parts[1]] - 1
        
        elif cmd == 'JG':
            if not self.zero_flag and not self.negative_flag:
                self.pc = self.labels[parts[1]] - 1
        
        elif cmd == 'JLE':
            if self.zero_flag or self.negative_flag:
                self.pc = self.labels[parts[1]] - 1
        
        elif cmd == 'JGE':
            if self.zero_flag or not self.negative_flag:
                self.pc = self.labels[parts[1]] - 1
        
        # Memória
        elif cmd == 'LOAD_MEM':
            reg_dest = parts[1]
            reg_addr = parts[2]
            addr = self.registers[reg_addr]
            self.registers[reg_dest] = self.memory[addr]
        
        elif cmd == 'STORE_MEM':
            reg_value = parts[1]
            reg_addr = parts[2]
            addr = self.registers[reg_addr]
            self.memory[addr] = self.registers[reg_value]
        
        # Sensores
        elif cmd == 'SENSOR':
            sensor_name = parts[1]
            reg = parts[2]
            if sensor_name in self.sensors:
                self.registers[reg] = self.sensors[sensor_name]
                print(f"  → Sensor {sensor_name} = {self.sensors[sensor_name]}")
        
        # Atuadores
        elif cmd == 'ACTUATOR':
            actuator = parts[1]
            value = self.get_value(parts[2])
            
            if actuator in self.actuators:
                self.actuators[actuator] = value
                print(f"  → Atuador {actuator} = {value}")
                
                # Simular ações físicas
                if actuator == 'GRINDER' and value == 1:
                    print("     ☕ Moendo grãos...")
                elif actuator == 'HEATER' and value > 0:
                    print(f"     🔥 Aquecendo para {value}°C...")
                    self.sensors['CURRENT_TEMP'] = value  # Simula aquecimento
                elif actuator == 'PUMP' and value == 1:
                    print("     💧 Bomba ativada...")
                elif actuator.startswith('VALVE_') and value > 0:
                    liquid = actuator.replace('VALVE_', '')
                    print(f"     💧 Dispensando {value}ml de {liquid}...")
        
        # Display
        elif cmd == 'DISPLAY':
            message = ' '.join(parts[1:]).strip('"')
            self.actuators['DISPLAY'] = message
            print(f"  📺 DISPLAY: {message}")
        
        # Espera
        elif cmd == 'WAIT':
            reg = parts[1]
            ms = self.registers[reg]
            seconds = ms / 1000.0
            print(f"  ⏱️  Aguardando {ms}ms ({seconds:.1f}s)...")
            time.sleep(min(seconds, 0.5))  # Limita espera real para demo
        
        # Rotinas
        elif cmd == 'CALL':
            routine = parts[1]
            self.call_stack.append(self.pc)
            self.pc = self.labels[routine] - 1
        
        elif cmd == 'RET':
            if self.call_stack:
                self.pc = self.call_stack.pop()
        
        # Controle
        elif cmd == 'HALT':
            print("\n  🛑 HALT - Programa finalizado")
            self.running = False
    
    def get_value(self, token):
        """Obtém valor de token (número, registrador ou variável)"""
        if token.startswith('R'):
            return self.registers[token]
        elif token in self.variables:
            return self.variables[token]
        else:
            try:
                return int(token)
            except ValueError:
                try:
                    return float(token)
                except ValueError:
                    return 0
    
    def print_state(self):
        """Imprime estado final da máquina"""
        print("\n📊 ESTADO FINAL DA VM:")
        print("-" * 60)
        
        print("\n🔢 Registradores:")
        for reg, value in self.registers.items():
            print(f"  {reg} = {value}")
        
        print("\n📦 Variáveis:")
        if self.variables:
            for var, value in self.variables.items():
                print(f"  {var} = {value}")
        else:
            print("  (nenhuma)")
        
        print("\n📡 Sensores:")
        for sensor, value in self.sensors.items():
            print(f"  {sensor} = {value}")
        
        print("\n⚙️  Atuadores:")
        for actuator, value in self.actuators.items():
            if value != 0 and value != "":
                print(f"  {actuator} = {value}")
        
        print("\n💾 Memória não-zero:")
        for i, val in enumerate(self.memory):
            if val != 0:
                print(f"  memory[{i}] = {val}")


def main():
    if len(sys.argv) < 2:
        print("Uso: python3 coffeevm.py <arquivo.asm> [--quiet]")
        print()
        print("Exemplos:")
        print("  python3 coffeevm.py output.asm")
        print("  python3 coffeevm.py output.asm --quiet")
        sys.exit(1)
    
    filename = sys.argv[1]
    verbose = '--quiet' not in sys.argv
    
    vm = CoffeeVM()
    vm.verbose = verbose
    
    try:
        vm.load_program(filename)
        vm.execute()
    except FileNotFoundError:
        print(f"❌ Erro: Arquivo '{filename}' não encontrado")
        sys.exit(1)
    except KeyError as e:
        print(f"❌ Erro: Label não encontrado: {e}")
        sys.exit(1)
    except Exception as e:
        print(f"❌ Erro durante execução: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)


if __name__ == "__main__":
    main()