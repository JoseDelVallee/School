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

# Subgráfica 2: Varianza a lo largo del tiempo para cada trayectoria
for i, (positions, _) in enumerate(trajectories):
    var = [np.var(positions[:j]) for j in range(1, num_steps)]
    ax2.plot(time[1:], var, label=f'Varianza de Trayectoria {i+1}')
ax2.set_title('Varianza de las trayectorias en función del tiempo')
ax2.set_xlabel('Tiempo')
ax2.set_ylabel('Varianza')
ax2.legend()

# Subgráfica 3: Histograma de los incrementos con ajuste normal para todas las trayectorias
colors = plt.cm.get_cmap('tab10', num_trajectories)  # Paleta de colores
for i, (_, increments) in enumerate(trajectories):
    ax3.hist(increments, bins=30, density=True, alpha=0.5, label=f'Trayectoria {i+1}', color=colors(i))

# Superponer la curva normal teórica (utilizando los incrementos de la primera trayectoria como referencia)
mean_increments = np.mean(trajectories[0][1])
std_increments = np.std(trajectories[0][1])
xmin, xmax = ax3.set_xlim()
x = np.linspace(xmin, xmax, 100)
p = norm.pdf(x, mean_increments, std_increments)
ax3.plot(x, p, 'k', linewidth=2, label='Curva Normal')
ax3.set_title('Histograma de los Incrementos de 10 Trayectorias')
ax3.set_xlabel('Incrementos')
ax3.set_ylabel('Densidad de Probabilidad')
ax3.legend()

plt.tight_layout()
plt.show()

# Cálculo y presentación de resultados
for i, (_, increments) in enumerate(trajectories):
    mean_increments = np.mean(increments)
    std_increments = np.std(increments)
