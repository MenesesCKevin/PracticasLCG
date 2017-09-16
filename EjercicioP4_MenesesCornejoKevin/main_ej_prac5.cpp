//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Meneses Cornejo Kevin Osmar				******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -10.0f;
float transX = 0.0;
float transY = 0.0;
float angleX = 0.0;
float angleY = 0.0;
int screenW = 0.0;
int screenH = 0.0;
float angCodo = 0.0f;
float angHombro = 0.0f;
float angMano = 0.0f;
float angPulgar1 = 0.0f;
float angPulgar2 = 0.0f;
float angInd1 = 0.0f;
float angInd2 = 0.0f;
float angInd3 = 0.0f;
float angMedi1 = 0.0f;
float angMedi2 = 0.0f;
float angMedi3 = 0.0f;
float angAnu1 = 0.0f;
float angAnu2 = 0.0f;
float angAnu3 = 0.0f;
float angMen1 = 0.0f;
float angMen2 = 0.0f;
float angMen3 = 0.0f;


void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			//glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		glTranslatef(transX, transY, transZ);
		glRotatef(angleX * 50, 1.0, 0.0, 0.0);
		glRotatef(angleY*50, 0.0, 1.0, 0.0);
		//Poner Código Aquí.
		

		//monito
		glPushMatrix();
		//cabeza
			glPushMatrix();
			glColor3f(0.0, 1.0, 0.0);
			prisma(); //0,0,0
		glPopMatrix();	

		//Cuello
			glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
				glTranslatef(0.0, -0.75, 0);
				glScalef(0.5,0.5,1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//torso
		glPushMatrix();
			glTranslatef(0.0, -2.5, 0.0);
			glScalef(3.0,3.0,1.0);
			glColor3f(0.0, 0.0, 1.0);
			prisma();
		glPopMatrix();

		//brazo derecho
		glPushMatrix();
		/*glTranslatef(-3.0, -1.5, 0.0);
		glScalef(3.0, 1.0, 1.0);
		glColor3f(0.0, 0.0, 1.0);
		prisma();*/
		glTranslatef(-1.75, -1.25, 0.0);
		glRotatef(270, 0.0, 0.0, 1.0);
		glRotatef(180, 0.0, 1.0, 0.0);
		/*
		glScalef(3.0, 1.0, 1.0);
		glColor3f(0.0, 0.0, 1.0);
		prisma();*/

			//hombro
			glRotatef(angHombro, 0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.5, 0.5, 1.0);
			glColor3f(0.0, 1.0, 1.0);
			prisma();
			glPopMatrix();

			//bicep

			glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
			glPopMatrix();
			//codo

			glTranslatef(0.0, -0.75, 0.0);
			glRotatef(angCodo, 0.0, 0.0, 1.0);
			glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
			glPopMatrix();
			//anteBrazo
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
			glPopMatrix();

			//mano
			glTranslatef(0.0, -0.75, 0.0);
			glRotated(angMano, 0.0, 0.0, 1.0);
			glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
			glPopMatrix();


			//pulgar
			glPushMatrix();
			glTranslatef(0.25, -0.75, 0.0);
			glRotatef(angPulgar1, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);

			glColor3f(0.0, 1.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();
			//parte 2
			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(angPulgar2, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.2, 0.1, 1.0);
			prisma();

			glPopMatrix();
			//INDICE
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glTranslatef(0.1, -0.35, 0.0);
			glRotatef(angInd1, 1.0, 0.0, 0.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte2
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angInd2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte3
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angInd3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();

			//medio
			//glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glTranslatef(0.1, -0.35, 0.0);
			glRotatef(angMedi1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, 0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte2
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angMedi2, 1.0, 0.0, 0.0);
			glTranslatef(-0.05, -0.10, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte3
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angMedi3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//anular
			//glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glTranslatef(0.1, -0.35, 0.0);
			glRotatef(angAnu1, 1.0, 0.0, 0.0);
			glTranslatef(-0.15, 0.0, 0.0);
			glColor3f(0.0, 1.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte2
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angAnu2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte3
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angAnu3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//meñique
			//glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glTranslatef(0.1, -0.35, 0.0);
			glRotatef(angMen1, 1.0, 0.0, 0.0);
			glTranslatef(-0.3, 0.0, 0.0);
			glColor3f(0.0, 1.0, 0.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte2
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angMen2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte3
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angMen3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.0, 1.0, 1.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
		glPopMatrix();

		/*mano derecho
		glPushMatrix();
		glTranslatef(-5.5, -1.5, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(1.0, 0.0, 1.0);
		prisma();
		glPopMatrix();*/

		/* mano izq
		glPushMatrix();
		glTranslatef(5.5, -1.5, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(1.0, 0.0, 1.0);
		prisma();
		glPopMatrix();*/

		//brazo izquierdo
		glPushMatrix();
		
		glTranslatef(1.75, -1.25, 0.0);
		glRotatef(90, 0.0, 0.0, 1.0); 

		/*
		glScalef(3.0, 1.0, 1.0);
		glColor3f(0.0, 0.0, 1.0);
		prisma();*/

			//hombro
			glRotatef(angHombro, 0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.5, 0.5, 1.0);
			glColor3f(0.0, 1.0, 1.0);
			prisma();
			glPopMatrix();

			//bicep

			glPushMatrix();
			glTranslatef(0.0, -0.75, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
			glPopMatrix();
			//codo

			glTranslatef(0.0, -0.75, 0.0);
			glRotatef(angCodo, 0.0, 0.0, 1.0);
			glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
			glPopMatrix();
			//anteBrazo
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
			glPopMatrix();

			//mano
			glTranslatef(0.0, -0.75, 0.0);
			glRotated(angMano, 0.0, 0.0, 1.0);
			glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glTranslatef(0.0, -0.75, 0.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
			glPopMatrix();


			//pulgar
			glPushMatrix();
			glTranslatef(0.25, -0.75, 0.0);
			glRotatef(angPulgar1, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);

			glColor3f(0.0, 1.0, 1.0);
			glPushMatrix();
			glScalef(0.2, 0.1, 1.0);
			prisma();
			glPopMatrix();
			//parte 2
			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(angPulgar2, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.2, 0.1, 1.0);
			prisma();

			glPopMatrix();
			//INDICE
			glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glTranslatef(0.1, -0.35, 0.0);
			glRotatef(angInd1, 1.0, 0.0, 0.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte2
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angInd2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 1.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte3
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angInd3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();

			//medio
			//glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glTranslatef(0.1, -0.35, 0.0);
			glRotatef(angMedi1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, 0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte2
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angMedi2, 1.0, 0.0, 0.0);
			glTranslatef(-0.05, -0.10, 0.0);
			glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte3
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angMedi3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//anular
			//glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glTranslatef(0.1, -0.35, 0.0);
			glRotatef(angAnu1, 1.0, 0.0, 0.0);
			glTranslatef(-0.15, 0.0, 0.0);
			glColor3f(0.0, 1.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte2
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angAnu2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 0.0, 1.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte3
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angAnu3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//meñique
			//glTranslatef(0.0, -0.75, 0.0);
			glPushMatrix();
			glTranslatef(0.1, -0.35, 0.0);
			glRotatef(angMen1, 1.0, 0.0, 0.0);
			glTranslatef(-0.3, 0.0, 0.0);
			glColor3f(0.0, 1.0, 0.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte2
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angMen2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(1.0, 1.0, 0.0);
			glPushMatrix();
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
			//parte3
			glTranslatef(0.0, -0.10, 0.0);
			glRotatef(angMen3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.10, 0.0);
			glColor3f(0.0, 1.0, 1.0);
			glScalef(0.1, 0.2, 1.0);
			prisma();
			glPopMatrix();
		glPopMatrix();

		//pierna derecha
		glPushMatrix();
		glTranslatef(-1.0, -7.5, 0.0);
		glScalef(1.0, 7.0, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		prisma();
		glPopMatrix();

		//pierna izquierda
		glPushMatrix();
		glTranslatef(1.0, -7.5, 0.0);
		glScalef(1.0, 7.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		//pata derecha
		glPushMatrix();
		glTranslatef(1.5, -12.5, 0.0);
		glScalef(3.0, 3.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
		glPopMatrix();

		//pata izquierda
		glPushMatrix();
		glTranslatef(-1.5, -12.5, 0.0);
		glScalef(3.0, 3.0, 1.0);
		glColor3f(0.0, 1.0, 0.0);
		prisma();
		glPopMatrix();


		
									
  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);
	

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
	case 'm':
		if (angMen1 < 90)
		angMen1 += 0.5f;
		break;
	case 'M':
		if (angMen1 >= 0)
		angMen1 -= 0.5f;
		break;
	case 'n':
		if (angAnu3 < 90)
		angAnu3 += 0.5f;
		break;
	case 'N':
		if (angAnu3 >= 0)
		angAnu3 -= 0.5f;
		break;
	case 'b':
		if (angAnu1 < 90)
		angAnu2 += 0.5f;
		break;
	case 'B':
		if (angAnu1 >= 0)
		angAnu2 -= 0.5f;
		break;
	case 'v':
		if (angAnu1 < 90)
		angAnu1 += 0.5f;
		break;
	case 'V':
		if (angAnu1 >= 0)
		angAnu1 -= 0.5f;
		break;
	case 'c':

		if (angMedi3<90)
		angMedi3 += 0.5f;
		break;
	case 'C':
		if (angMedi3 >= 0)
		angMedi3 -= 0.5f;
		break;
	case 'z':
		if (angMedi2<90)
		angMedi2 += 0.5f;
		break;
	case 'Z':
		if (angMedi2 >= 0)
		angMedi2 -= 0.5f;
		break;
	case 'x':
		if (angMedi1<90)
		angMedi1 += 0.5f;
		break;
	case 'X':
		if (angMedi1 >= 0)
		angMedi1 -= 0.5f;
		break;
	case 'j':
		if (angInd3<90)
		angInd3 += 0.5f;
		break;
	case 'J':
		if (angInd3 >= 0)
		angInd3 -= 0.5f;
		break;
	case 'h':
		if (angInd2<90)
		angInd2 += 0.5f;
		break;
	case 'H':
		if (angInd2 >= 0)
		angInd2 -= 0.5f;
		break;
	case 'g':
		if (angInd1<90)
		angInd1 += 0.5f;
		break;
	case 'G':
		if (angInd1>=0)
		angInd1 -= 0.5f;
		break;
	case 'F':
		if (angPulgar2<90)
		angPulgar2 += 0.5f;
		break;
	case 'f':
		if (angPulgar2 >= 0)
		angPulgar2 -= 0.5f;
		break;
	case 'p':
		if (angPulgar1<0)
		angPulgar1 += 0.5f;
		break;
	case 'P':
		if (angPulgar1 >= -90)
		angPulgar1 -= 0.5f;
		break;
	case 'i':
	case 'I':
		if (angMano<90)
		angMano += 0.5f;
		break;
	case 'o':
	case'O':
		if (angMano >= 0)
		angMano -= 0.5f;
		break;
	case 'y':
	case 'Y':
		if(angCodo<90)
		angCodo += 0.5f;
		break;
	case 'u':
	case 'U':
		if (angCodo>=0)
		angCodo -= 0.5f;
		break;
	case 'r':
	case 'R':
		if (angHombro<90)
		angHombro += 0.5f;
		break;
	case 't':
	case 'T':
		if(angHombro>=-90)
		angHombro -= 0.5f;
		break;
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
	case 'q':
	case 'Q':
		transY += 0.2f;
		break;
	case 'e':
	case 'E':
		transY -= 0.2f;
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
  case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
	  angleX += 2.0f;
	  break;
  case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
	  angleX -= 2.0f;
	  break;
  case GLUT_KEY_LEFT:
	  angleY += 2.0f;
	  break;
  case GLUT_KEY_RIGHT:
	  angleY -= 2.0f;
	  break;
  default:
	  break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}