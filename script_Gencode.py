import os
import subprocess

number_test_ko=0
number_test_ok=0

nb_error_ko=0
nb_error_ok=0


#prend en entrée un chemin de fichier et compte le nombre d'anomalies
def execute_ko(chemin_fichier):
	global nb_error_ko
	process = subprocess.Popen(["./minicc", chemin_fichier], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

	output, error = process.communicate()

	output_str = output.decode()

	if("Error line 7" in output_str):
		nb_error_ko=nb_error_ko+1
	else:
		print("DEBUG fichier problématique : ", chemin_fichier)
		print(output_str)


    
#prend en entrée un chemin de fichier et compte le nombre d'anomalies
def execute_ok(chemin_fichier):
	global nb_error_ok
	process = subprocess.Popen(["./minicc", chemin_fichier], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

	output, error = process.communicate()

	output_str = output.decode()

	if("Error" in output_str):
		print("DEBUG fichier problématique : ", chemin_fichier)
		print(output_str)
		nb_error_ok=nb_error_ok+1

  




#KO
#recupération l'emplacement du script
repertoire = os.getcwd() 
repertoire = (os.path.join(repertoire, "Tests/Gencode/KO")) # le chemin des fichiers de tests

fichiers = os.listdir(repertoire) #liste des fichiers du repertoire KO

number_test_ko=len(fichiers) # nombre de fichiers dans le repertoire ko

for nom_fichier in fichiers:
	chemin = os.path.join(repertoire, nom_fichier) #ajout au chemin, le fichier à executer
	execute_ko(chemin)


print("-------------------------------------------------------------")
print("-------------------------------------------------------------")
print("-------------------------------------------------------------")

print("Repertoire testée: ", repertoire)  
print("Rapport test ko : \n")  

print("nombres de test éxecuté : ", number_test_ko)
print("nombre d'erreur en ligne 7 pour la section ko", nb_error_ko)


#Méthode identique pour OK
#OK
repertoire = os.getcwd()
repertoire = (os.path.join(repertoire, "Tests/Gencode/OK"))

fichiers = os.listdir(repertoire)

number_test_ok=len(fichiers) # nombre de fichiers dans le repertoire ok

for nom_fichier in fichiers:
    chemin = os.path.join(repertoire, nom_fichier)
    execute_ok(chemin)
    
#on teste si le nombre d'erreur = le nombre de test KO:    
# si oui alors tout les tests se sont déroulés avec succès
#si un des test ok produit une erreurs alors il y à un pb
  
print("\n\nRapport test ok : \n")  
print("nombres de test éxecuté : ", number_test_ok)
print("nombre d'erreurs pour la section ok", nb_error_ok)

if(nb_error_ok==0):
	if(nb_error_ko==number_test_ko):
		print("\n\n----Le compilateur à réussit tout les tests----\n\n")
	else:
		print("\n\n----Le compilateur à échoué aux test ko    ----\n\n")
else:	
	if(nb_error_ko==number_test_ko):
		print("\n\n----Le compilateur à réussit tout les tests----\n\n")
	else:
		print("\n\n----Le compilateur à échoué aux test ko    ----\n\n")
	print("\n\n----Le compilateur à échoué aux test ok    ----\n\n")
print("------------------------------------------------------------")
print("------------------------------------------------------------")
print("------------------------------------------------------------")




