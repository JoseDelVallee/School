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

kf = KFold(n_splits=5)
# Funcion para validación cruzada

def validacionCruzada(model, x_train, y_train, kf):
    accuracies = []

    for train_index, test_index in kf.split(x_train):
        X_train_fold, X_test_fold = x_train[train_index], x_train[test_index]
        y_train_fold, y_test_fold = y_train[train_index], y_train[test_index]

        model.fit(X_train_fold, y_train_fold)
        score = model.score(X_test_fold, y_test_fold)
        accuracies.append(score)

    return np.array(accuracies)
gnb_iris = GaussianNB()
mnb_iris = MultinomialNB()
gnb_iris_accuracies = validacionCruzada(gnb_iris, x_train, y_train, kf)
mnb_iris_accuracies = validacionCruzada(mnb_iris, x_train, y_train, kf)

def imprimir(nombre, accuracies):
    print(nombre)
    for i, acc in enumerate(accuracies):
        print(f"pliegue {i+1}: {acc}")
    print("Promedio: ", accuracies.mean())

imprimir("Gauss", gnb_iris_accuracies)
imprimir("Multinomial", mnb_iris_accuracies)
