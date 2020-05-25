#include "opésSeuillage.h"


/* 0: binaire
1 : Binaire inversé
2 : seuil tronqué
3 : Seuil à zéro
4 : Seuil à zéro inversé
*/
Mat opésSeuillage::SeuilBin(Mat _img, int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil,255,0 ); //255 étant la valeur max de seuil 
	
	return  _img;
}

Mat opésSeuillage::SeuilBinInv(Mat _img , int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil, 255, 1);
	return  _img;
}

Mat opésSeuillage::Tronquer(Mat _img, int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil, 255,2);
	return  _img;
}

Mat opésSeuillage::SeuilaZero(Mat _img, int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil, 255, 3);
	return  _img;
}

Mat opésSeuillage::SeuilaZeroInv(Mat _img, int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil, 255, 4);
	return _img;
}
/* A tester pour déceler d'eventuelles coquilles

*/