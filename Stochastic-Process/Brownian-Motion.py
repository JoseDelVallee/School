# Movimiento browniano
# Importación de bibliotecas

import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm

# Parámetros de la simulación
num_steps = 1000       # Número de pasos de la simulación
step_size = 1          # Tamaño del paso (desviación estándar de los incrementos)
time_range = 10        # Duración total del tiempo
initial_position = 0   # Posición inicial de la partícula
time = np.linspace(0, time_range, num_steps)  # Rango de tiempo

# Función para simular el movimiento browniano
def simulate_brownian_motion(num_steps, step_size, initial_position):
    increments = np.random.normal(0, step_size, num_steps)
    positions = np.cumsum(increments) + initial_position
    return positions, increments
    
# Simulación para diez trayectorias de comparación
num_trajectories = 10
trajectories = [simulate_brownian_motion(num_steps, step_size, initial_position) for _ in range(num_trajectories)]

# Crear la figura con tres subgráficas
fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(18, 5))

# Subgráfica 1: Trayectorias del movimiento browniano
for i, (positions, _) in enumerate(trajectories):
    ax1.plot(time, positions, label=f'Trayectoria {i+1}')
ax1.set_title('Comparación de diez trayectorias brownianas')
ax1.set_xlabel('Tiempo')
ax1.set_ylabel('Posición')
ax1.legend()
