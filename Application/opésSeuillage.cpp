#include "op�sSeuillage.h"


/* 0: binaire
1 : Binaire invers�
2 : seuil tronqu�
3 : Seuil � z�ro
4 : Seuil � z�ro invers�
*/
Mat op�sSeuillage::SeuilBin(Mat _img, int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil,255,0 ); //255 �tant la valeur max de seuil 
	
	return  _img;
}

Mat op�sSeuillage::SeuilBinInv(Mat _img , int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil, 255, 1);
	return  _img;
}

Mat op�sSeuillage::Tronquer(Mat _img, int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil, 255,2);
	return  _img;
}

Mat op�sSeuillage::SeuilaZero(Mat _img, int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil, 255, 3);
	return  _img;
}

Mat op�sSeuillage::SeuilaZeroInv(Mat _img, int _Type, double _valseuil)
{
	threshold(_img, _img, _valseuil, 255, 4);
	return _img;
}
/* A tester pour d�celer d'eventuelles coquilles

*/