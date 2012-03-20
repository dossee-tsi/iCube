#include "PinguinFlight.h"
#include <cstdio>
#include <QtGui/QImage>
#include <QtGui/QColor>
#include <QtGui/QPainter>
#include <QtGui/QImage>
#include <QtGui/QColor>
#include <QtGui/QTransform>
#include <QtCore/QRect>

#include <opencv/highgui.h>

// Here goes member definition

//


//---------------------------------------------------------------
// Slot to subscribe for event.
// Expects to receive array of pointers on quadrilaterals instances which were recognized
//---------------------------------------------------------------

PinguinFlight::PinguinFlight()
{
	chosenImage=0;

	penguin0a = QImage("./Logic/PinguinFlight/pinguin0a.png");
	penguin90a = QImage("./Logic/PinguinFlight/pinguin90a.png");
	penguin180a = QImage("./Logic/PinguinFlight/pinguin180a.png");
	penguin270a = QImage("./Logic/PinguinFlight/pinguin270a.png");
	penguin0b = QImage("./Logic/PinguinFlight/pinguin0b.png");
	penguin90b = QImage("./Logic/PinguinFlight/pinguin90b.png");
	penguin180b = QImage("./Logic/PinguinFlight/pinguin180b.png");
	penguin270b = QImage("./Logic/PinguinFlight/pinguin270b.png");


}

void PinguinFlight::ProcessSquares (const Square *recognizedSquares, int size)
{
	Image *images = new Image [size];



	for (int i=0; i < size; i++)
	{
		QImage *img;
		if(recognizedSquares[i].GetAngle() == 0) {
			if(chosenImage==0){
				img = &penguin0a;
			} else {
				img = &penguin0b;
			}
		}
		else if(recognizedSquares[i].GetAngle() == 90) {
			if(chosenImage==0){
				img = &penguin90a;
			} else {
				img = &penguin90b;
			}		}
		else if(recognizedSquares[i].GetAngle() == 180) {
			if(chosenImage==0){
				img = &penguin180a;
			} else {
				img = &penguin180b;
			}		}
		else if(recognizedSquares[i].GetAngle() == 270) {
			if(chosenImage==0){
				img = &penguin270a;
			} else {
				img = &penguin270b;
			}		}
		CvPoint centCoord = recognizedSquares [i].GetCenterCoordinates ();
		images[i] = Image (*img, QPoint (centCoord.x, centCoord.y));
	}

	if(chosenImage==0){
		chosenImage=1;
	} else {
		chosenImage=0;
	}

	emit SquaresProcessed (images, size);
	delete [] images;
}


//---------------------------------------------------------------
// Destructor.
// Releases used resources.
//---------------------------------------------------------------

PinguinFlight::~PinguinFlight ()
{

}

//void GetColor()
