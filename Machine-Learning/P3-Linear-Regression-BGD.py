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


# Programa 2 Dataset y visualización
datos = pd.read_csv('/content/drive/MyDrive/Prácticas Machine Learning/Práctica3-Regresión-Lineal-con-BGD-Machine-Learning/Dataset_multivariable.csv')
datos

# Dividimos los datos
x = datos.iloc[:, :-1]
y = datos.iloc[:, -1:]


# Dividimos los datos en conjuntos de entrenamiento(70%) y prueba(30%)
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=0, shuffle=True)


x_train = np.array(x_train)
y_train = np.array(y_train)
x_test = np.array(x_test)
y_test = np.array(y_test)


# Función para calcular el error de aproximación.
def approximation_Error(x_test, y_test):
    error = 0
    for i in range(3):
        error += abs(x_test[i] - y_test[i])
    return error

# Función para realizar el (BGD).
def BGD(datos, w0, alpha):
    for id_x in range(len(w0)):
        suma_total = 0  # Inicializamos la suma de errores

        for j in range(len(datos)):
            suma_total += ((w0[id_x] * datos[j][id_x]) - y_train[j]) * datos[j][id_x]


        w0[id_x] -= 2 * alpha * suma_total
    return w0
# Parámetros iniciales
weight = np.zeros(5)  # Inicialización w en 0
alpha = 0.000006      # Tasa de aprendizaje
iters = 4           # Número de iteraciones

# Listas para almacenar los valores
weights = []
preds = []
errors = []

# Ejecución de las iteraciones de BGD
for iteracion in range(iters):
    weight = BGD(x_train, weight, alpha)
    weights.append(weight.copy())

    # Calculo las predicciones
    y_pred = np.dot(x_test, weight)
    preds.append(y_pred)

    # Calculo el error de estimación
    error_estimacion = approximation_Error(y_pred, y_test)
    errors.append(error_estimacion)

# Función para imprimir los resultados
def imprimir_resultados(arr, iters):
    for i in range(iters):
        print(f"Iteración {i + 1}: ", arr[i])

# Resultados de las iteraciones
# Pesos (w) en cada iteración
print("\n\n\nPesos (w) en cada iteración:")
imprimir_resultados(weights, iters)

# Valores reales (y_test)
print("\nValores reales (y_test):")
print(f"{y_test}")

# Predicciones en cada iteración (y_pred)
print("\nPredicciones en cada iteración (y_pred):")
imprimir_resultados(preds, iters)
