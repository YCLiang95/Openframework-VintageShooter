#include "Pawn.h"



Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}

void Pawn::draw() {
	cout << "draw pawn" << endl;
	ofPushMatrix();
	ofTranslate(transform.getPosition());
	ofRotate(transform.angle);
	sprite.image.draw(0, 0);
	ofPopMatrix();
}
