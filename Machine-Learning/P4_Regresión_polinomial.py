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
