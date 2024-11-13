# Importar Bibliotecas
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.model_selection import train_test_split

# Dataset y su visualización
df = pd.read_csv("/content/drive/MyDrive/Prácticas Machine Learning/Práctica3-Regresión-Lineal-con-BGD-Machine-Learning/casas.csv")
df

# Asignamos las columnas

x = df['Terreno (m2)'].values
y = df['Precio (MDP)'].values

# Dividimos los datos en conjuntos de entrenamiento y prueba
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, shuffle=True, random_state=0)

# Definimos la función (BGD)
def BGD(x, y, x_test, y_test, iters, alpha, weight):
    wi = 0
    sumA = 0
    preds = []
    errors = []
    wi_values = []
