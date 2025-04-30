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

if gnb_iris_accuracies.mean() > mnb_iris_accuracies.mean():
    modelo_chido, nombre = gnb_iris, "GaussianNB_iris"
else:
    modelo_chido, nombre = mnb_iris, "MultinomialNB_iris"

modelo_chido.fit(x_train, y_train)
prediccion = modelo_chido.predict(x_test)
print(f"reporte de clasificacion de {nombre}")
print(classification_report(y_test, prediccion))

# Matriz de confusión

matriz_de_conf = confusion_matrix(y_test, prediccion)
matriz = ConfusionMatrixDisplay(confusion_matrix=matriz_de_conf,display_labels=modelo_chido.classes_)
matriz.plot()
plt.show()
##Programa 2
# Dataset y su visualización

dfEmails = pd.read_csv("/content/drive/MyDrive/Prácticas Machine Learning/Práctica5_Naïve Bayes_Machine_Learning/emails.csv").iloc[:, 1:]
dfEmails

# Dividir el conjunto de datos en entrenamiento (70%) y prueba (30%)

x_train2, x_test2, y_train2, y_test2 = train_test_split(x,y,test_size=0.3,random_state=0)
kf2 = KFold(n_splits=5)

gnb_emails = GaussianNB()
mnb_emails = MultinomialNB()
gnb_emails_accuracies = validacionCruzada(gnb_emails,x_train2, y_train2, kf2)
mnb_emails_accuracies = validacionCruzada(mnb_emails, x_train2, y_train2, kf2)

imprimir("Gauss", gnb_emails_accuracies)
imprimir("Multinomial", mnb_emails_accuracies)

if gnb_iris_accuracies.mean() > mnb_iris_accuracies.mean():
    modelo_chido, nombre = gnb_iris, "GaussianNB_iris"
else:
    modelo_chido, nombre = mnb_iris, "MultinomialNB_iris"
modelo_chido.fit(x_train, y_train)
prediccion = modelo_chido.predict(x_test)
print(f"reporte de clasificacion de {nombre}")
print(classification_report(y_test, prediccion))

# Matriz de confusión
matriz_de_conf = confusion_matrix(y_test, prediccion)
matriz = ConfusionMatrixDisplay(confusion_matrix=matriz_de_conf,display_labels=modelo_chido.classes_)
matriz.plot()
plt.show()

# Dataset y su visualización
dfEmails = pd.read_csv("/content/drive/MyDrive/Prácticas Machine Learning/Práctica5_Naïve Bayes_Machine_Learning/emails.csv").iloc[:, 1:]
dfEmails
x,y = dfEmails.drop("Prediction", axis=1).values, dfEmails["Prediction"].values
x,y

# Dividir el conjunto de datos en entrenamiento (70%) y prueba (30%)
x_train2, x_test2, y_train2, y_test2 = train_test_split(x,y,test_size=0.3,random_state=0)

kf2 = KFold(n_splits=5)
gnb_emails = GaussianNB()
mnb_emails = MultinomialNB()
