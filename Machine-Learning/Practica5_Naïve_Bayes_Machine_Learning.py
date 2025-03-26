# Importar Bibliotecas

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split, KFold
from sklearn.naive_bayes import GaussianNB, MultinomialNB
from sklearn.metrics import confusion_matrix, classification_report, ConfusionMatrixDisplay
import matplotlib.pyplot as plt

# Dataset y su visualización

dfIris = pd.read_csv("/content/drive/MyDrive/Prácticas Machine Learning/Práctica5_Naïve Bayes_Machine_Learning/iris.csv")
dfIris

x, y = dfIris.drop("species", axis=1).values, dfIris["species"].values

# Dividir el conjunto de datos en entrenamiento (70%) y prueba (30%)
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.3,random_state=0)
