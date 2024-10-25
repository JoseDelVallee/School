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
