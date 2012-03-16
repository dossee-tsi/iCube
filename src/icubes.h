#ifndef ICUBES_H
#define ICUBES_H

#include "Recognition/FrameProcessor.h"
#include "Recognition/Square.h"
#include "Logic/Image.h"
#include "Logic/ModuleBinaryMath/BinaryMath.h"
#include "Logic/ModuleColorPalette/ColorPalette.h"
#include "Logic/PinguinFlight/PinguinFlight.h"
#include <QtGui/QMainWindow>
#include <QLabel>
#include "ui_icubes.h"

class iCubes : public QMainWindow
{
    Q_OBJECT

	public:
		iCubes(QWidget *parent = 0);
		void setupModule(QObject *module);
		~iCubes();

	public slots:
		void ShowObjects (const Image*, int);

		void demoSquares();

		void ShowConfigureDialog ();

	private:
		const static int SIZE = 8;

		Ui::iCubesClass ui;

		FrameProcessor m_videoStreamProcessor;
		BinaryMath m_objectProcessor;
		ColorPalette *palette;
		PinguinFlight *pinguinFlight;
		QLabel *labels[SIZE];

};

#endif // ICUBES_H
