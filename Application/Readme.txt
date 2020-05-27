Application de traitement d’image

Cette application console et une application de traitement d’image partir de son chemin absolu. L’image doit se situer dans le dossier racine de l’ordinateur (disque C:/ où se situe windows) ou dans n’importe quelle clé USB ou disque ne contenant pas windows.
L’application permet d’effectuer les traitements suivants :
* Filtrage :
	- Filtre médian
	- Filtre gaussien
* Dérivation :
	- Calcul du gradient dans une image (Sobel)
* Opérations de morphologie mathématique :
	- Dilatation
	- Érosion
* Détection de contours :
	- Application d’un détecteur de contours « Canny »
* Segmentations d’images :
	- Opérations de seuillages
	- Segmentation par croissance de région

Utilisation :
1. L’utilisateur rentre le chemin d’accès de l’image comme indiqué sur l’application.

2. Une fois que l’image est chargée on a accès au menu comprenant tous les traitements que l’application peux effectuer. Il suffit de rentrer dans la commande le numéro associé au traitement que l’on veut effectuer.
Sur certains traitements il est demandé un la catégorie du traitement, là encore il suffit de rentrer le numéro correspondant au à la catégorie souhaitée.
Selon les traitements, il sera demandé de rentrer une valeur pour choisir (le plus souvent) l’intensité du traitement.
Une fois le traitement effectué il est possible d’enregistrer la modification ou non.
Si on garde la modification il nous est ensuite possible d’effectuer un autre traitement.
Si on ne grade pas les modifications on revient sur la page du traitement que l’on était en train de faire. 
A noter que l’on peut revenir en arrière dans le menu à tout moment.

3. Pour sauvegarder, il suffit de faire quitter (11 dans le menu principal) ou alors de changer d'image (10). Ensuite il sera demandé de rentrer le chemin d’accès où sera enregistrée l’image suivit de son nom (ne pas l’appeler comme l’image d’origine si elles sont toutes deux enregistrées dans le même dossier).

Lien:
* UML :
	https://app.lucidchart.com/publicSegments/view/45243c56-8d31-44b1-affd-81c7ba521131

* GitHub :
	https://github.com/LeBourguignon/TP-c-

Pour plus de question ne pas hésiter a nous contacter.
Baptiste ANDRES et Clément GHYS



