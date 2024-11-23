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

# Imprimimos los valores de la iteracion
        print(f"Iteración {iteration + 1}:")
        print(f"  w = {wi}")
        print(f"  y_test = {y_test}")
        print(f"  y_pred = {y_pred}")
        print(f"  Error de estimación = {error}\n")
    return preds, errors, wi_values

# Definimos los parámetros para el entrenamiento
iters = 4            # Iteraciones para BGD
alpha = 0.00000007
weight = 0.0         # Peso inicial

# Funcion para BGD
preds, errors, wi_values = BGD(x_train, y_train, x_test, y_test, iters, alpha, weight)

# Graficas
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 6))

# Gráfico de regresión lineal
for i in range(iters):
    ax1.plot(x_test, preds[i], label=f'Iteración {i+1}')
ax1.scatter(x_test, y_test, color='red')
ax1.set_title('Regresión Lineal')
ax1.set_xlabel('Terreno (m2)')
ax1.set_ylabel('Precio (MDP)')
ax1.legend()


# Gráfico de error de estimación
ax2.scatter(np.arange(1, iters + 1), errors, color='red')
ax2.set_title('Error de Estimación')
ax2.set_xlabel('Iteración')
ax2.set_ylabel('Error')

plt.show()

