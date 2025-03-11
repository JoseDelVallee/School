# Importar Bibliotecas

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.pipeline import make_pipeline
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression, SGDRegressor
from sklearn.preprocessing import PolynomialFeatures, StandardScaler, RobustScaler
from sklearn.metrics import mean_squared_error, r2_score

# Dataset y su visualización

df = pd.read_csv('/content/drive/MyDrive/Prácticas Machine Learning/Práctica 4_Regresión_polinomial_Machine_Learning/datos.csv')
df

# Asignamos las columnas
x = df['x'].values.reshape(-1, 1)  # Se cambia de x a bidimensional
y = df['y'].values

# Dividimos los datos en conjuntos de entrenamiento y prueba
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, shuffle=True, random_state=0)

# Entrenamos el modelo
linear_OLS_model = LinearRegression()
linear_OLS_model.fit(x_train, y_train)

# Realizamos predicciones
y_pred_linear_OLS_model = linear_OLS_model.predict(x_test)

# Calculamos las métricas
mse_linear_regression_OLS = mean_squared_error(y_test, y_pred_linear_OLS_model)
r2_linear_regression_OLS = r2_score(y_test, y_pred_linear_OLS_model)

# Visualizacion de la grafica
plt.scatter(x_test, y_test, color='blue', label='y_test')
plt.plot(x_test, y_pred_linear_OLS_model, color="red", label='y_pred')
plt.xlabel('x_test')
plt.ylabel('y_test / y_pred')
plt.title("Regresion lineal con OLS")
plt.legend()
plt.show()

# Metricas
print("Regresion lineal con OLS\n", mse_linear_regression_OLS,"         ", r2_linear_regression_OLS)

# Creamos la transformación polinomial (grado 2)
poly_features_OLS = PolynomialFeatures(degree=2)

# Aplicamos la transformación polinomial sobre x_train
x_poly_2_OLS = poly_features_OLS.fit_transform(x_train)

# Inicializamos el modelo
model_2_OLS = LinearRegression()

# Ajustamos el modelo
model_2_OLS.fit(x_poly_2_OLS, y_train)

# Predicciones sobre el conjunto de prueba usando el x_train
y_pred_2_OLS = model_2_OLS.predict(poly_features_OLS.transform(x_test))

# Calculamos el (MSE)
mse_poly_2_OLS = mean_squared_error(y_test, y_pred_2_OLS)

# Calculamos R^2
r2_poly_2_OLS = r2_score(y_test, y_pred_2_OLS)

# Creamos un DataFrame para almacenar las predicciones junto con los valores de 'x_test' para visualizarlos
dataframe = pd.DataFrame({'x_test': x_test.flatten(), 'y_pred_2_OLS': y_pred_2_OLS})
dataframe_sorted = dataframe.sort_values(by='x_test')

# Visualizacion de la grafica
plt.scatter(x_test, y_test, color='blue', label='y_test')
plt.plot(dataframe_sorted['x_test'], dataframe_sorted['y_pred_2_OLS'], color = "red")
plt.xlabel('x_test')
plt.ylabel('y_test / y_pred')
plt.title("Regresion polinomial grado 2 con OLS")
plt.legend()
plt.show()

# Metricas
print("Regresion polinomial grado 2 con OLS \n", mse_poly_2_OLS,"        ", r2_poly_2_OLS)

# Creamos la transformación polinomial (grado 3)
poly_features_OLS_3 = PolynomialFeatures(degree=3)

# Aplicamos la transformación polinomial sobre x_train
x_poly_3_OLS = poly_features_OLS_3.fit_transform(x_train)

# Inicializamos el modelo de regresión lineal
model_3_OLS = LinearRegression()

# Ajustamos el modelo
model_3_OLS.fit(x_poly_3_OLS, y_train)

# Realizamos predicciones usando el modelo ajustado
y_pred_3_OLS = model_3_OLS.predict(poly_features_OLS_3.transform(x_test))

# Calculamos el (MSE)
mse_poly_3_OLS = mean_squared_error(y_test, y_pred_3_OLS)

# Calculamos (R^2)
r2_poly_3_OLS = r2_score(y_test, y_pred_3_OLS)

dataframe['y_pred_3_OLS'] = y_pred_3_OLS
dataframe_sorted = dataframe.sort_values(by='x_test')

# Visualización de la gráfica:
plt.scatter(x_test, y_test, color='blue', label='y_test')
plt.plot(dataframe_sorted['x_test'], dataframe_sorted['y_pred_3_OLS'], color="red", label='y_pred_3_OLS')
plt.xlabel('x_test')
plt.ylabel('y_test / y_pred')
plt.title("Regresión polinomial grado 3 con OLS")
plt.legend()

# Mostramos el gráfico
plt.show()

# Imprimimos las métricas de evaluación
print("Regresión polinomial grado 3 con OLS\n", mse_poly_3_OLS, "         ", r2_poly_3_OLS)

# Definimos el modelo con descenso de gradiente estocástico (SGD)
linear_SGD_model = SGDRegressor(learning_rate='constant', max_iter=10000, eta0=0.0000001)

# Ajustamos el modelo con (x_train, y_train)
linear_SGD_model.fit(x_train, y_train.ravel())

# Predicciones con el modelo entrenado sobre (x_test).
y_pred_linear_SGD_model = linear_SGD_model.predict(x_test)

# Calculamos el Error Cuadrático Medio (MSE)
mse_linear_regression_SGD = mean_squared_error(y_test, y_pred_linear_SGD_model)

# Calculamos el coeficiente de determinación (R^2)
r2_linear_regression_SGD = r2_score(y_test, y_pred_linear_SGD_model)

# Graficamos los resultados
plt.scatter(x_test, y_test, color='blue', label='y_test')
plt.plot(x_test, y_pred_linear_SGD_model, color="red")
plt.xlabel('x_test')
plt.ylabel('y_test / y_pred')
plt.title("Regresion lineal con SGD")
plt.legend()
plt.show()

# Imprimimos las métricas
print("Regresión lineal con SGD\n ", mse_linear_regression_SGD, "         ", r2_linear_regression_SGD)

# Función para el calculo de MSE y R2
def total(x_test, y_test, regresion):
    prediction = regresion.predict(x_test)
    mse = mean_squared_error(y_test, prediction)
    r2 = r2_score(y_test, prediction)
    return mse, r2

# Función para graficar los resultados
def Grafica_Regresion(x_test, y_test, y_pred, title):
    plt.scatter(x_test, y_test, color='blue', label='Datos de prueba')
    plt.plot(x_test, y_pred, color='red', label='Predicción')
    plt.xlabel('x_test')
    plt.ylabel('y_test / y_pred')
    plt.title(title)
    plt.legend()
    plt.show()

# Función de regresión polinómica de grado 3 con SGD
def RegresionSGD_grado_3(x_train, y_train, x_test, y_test):
    model_SGD_poly_3 = make_pipeline(PolynomialFeatures(degree=3), SGDRegressor(learning_rate='constant', max_iter=10000, eta0=0.0000001))
    model_SGD_poly_3.fit(x_train.reshape(-1, 1), y_train)

    # Evaluar el modelo
    mse_poly_3, r2_poly_3 = total(x_test.reshape(-1, 1), y_test, model_SGD_poly_3)

    # Predicción y graficar los resultados
    indices = np.argsort(x_test)  # Ordenar x_test para que la gráfica sea continua
    y_pred_poly_3 = model_SGD_poly_3.predict(x_test[indices].reshape(-1, 1))
    Grafica_Regresion(x_test[indices], y_test[indices], y_pred_poly_3, 'Regresión polinomial con SGD de grado 3')
    return mse_poly_3, r2_poly_3


# Dividir los datos en conjunto de entrenamiento y prueba
x = data['x'].values
y = data['y'].values
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=0, shuffle=True)

# Llamar a la función de regresión con SGD para grado 3 y almacenar los resultados
mse_poly_3_SGD, r2_poly_3_SGD = RegresionSGD_grado_3(x_train, y_train, x_test, y_test)

# Imprimir los resultados de MSE y R² fuera de la función
print("Regresión Polinómica con SGD de grado 3\n", mse_poly_3_SGD, "    ", r2_poly_3_SGD)

# Imprimir los resultados de MSE y R² fuera de la función
print("Regresión Polinómica con SGD de grado 3\n", mse_poly_3_SGD, "    ", r2_poly_3_SGD)

print("Resumen de los resultados\n")
print("Regresiones                                             mse                   r2\n")
print("Regresion lineal con OLS                   ", mse_linear_regression_OLS, "         ", r2_linear_regression_OLS)
print("Regresion polinomial grado 2 con OLS       ", mse_poly_2_OLS, "        ", r2_poly_2_OLS)
print("Regresion polinomial grado 3 con OLS       ", mse_poly_3_OLS, "         ", r2_poly_3_OLS)
print("Regresion lineal con SGD                   ", mse_linear_regression_SGD, "         ", r2_linear_regression_SGD)
print("Regresion polinomial grado 2 con SGD       ", mse_poly_2_SGD, "        ", r2_poly_2_SGD)
print("Regresion polinomial grado 3 con SGD       ", mse_poly_3_SGD, "          ", r2_poly_3_SGD)


#Programa 2
#Importar bibliotecas
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn import preprocessing
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.model_selection import train_test_split
import operator



# Dataset y su visualización

df = pd.read_csv('/content/drive/MyDrive/Prácticas Machine Learning/Práctica 4_Regresión_polinomial_Machine_Learning/cal_housing.csv')
df

# Asignamos las columnas
X = df.iloc[:, :-1].values
Y = df.iloc[:,-1].values


# Dividimos los datos en conjuntos de entrenamiento y prueba
x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size=0.2, shuffle=True, random_state=0)

# Crear modelo de regresión lineal
linear_model = LinearRegression()


# Ajustar el modelo a (x_train, y_train)
linear_model.fit(x_train, y_train)


#Prediccion con el modelo ajustado utilizando (x_test)
y_pred_linear_model = linear_model.predict(x_test)


# Calcular el Error Cuadrático Medio (MSE)
mse_linear_regression = mean_squared_error(y_test, y_pred_linear_model)

# Calcular el coeficiente de determinación R²
r2_linear_regression = r2_score(y_test, y_pred_linear_model)

# Crear modelo polinomial con grado 2
poly_features_2 = preprocessing.PolynomialFeatures(degree=2)

# Transformar los datos de entrenamiento y prueba
x_poly_train_2 = poly_features_2.fit_transform(x_train)
x_poly_test_2 = poly_features_2.transform(x_test)

# Crear una instancia de regresión lineal
model_2 = LinearRegression()


# Ajustar el modelo de regresión lineal a los datos de entrenamiento
model_2_std.fit(x_train_poly_2_std, y_train)

#Prediccion con el modelo ajustado utilizando datos de prueba estandarizados
y_pred_2_std = model_2_std.predict(x_test_poly_2_std)
