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
