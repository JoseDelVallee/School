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
# Proceso de BGD para el número de iteraciones
    for iteration in range(iters):
        for j in range(len(x)):
            sumA += ((wi * x[j]) - y[j]) * x[j]
        wi = wi - alpha * (2 * sumA)
        wi = wi - weight
        weight = wi

# Calculo de las predicciones para el conjunto de prueba
        y_pred = [np.dot(xi, wi) for xi in x_test]
        preds.append(y_pred)

# Calculo de del error absoluto para el conjunto de prueba
        error = sum(abs((y_pred[k] - y_test[k])) for k in range(len(y_test)))
        errors.append(error)
        wi_values.append(wi)
