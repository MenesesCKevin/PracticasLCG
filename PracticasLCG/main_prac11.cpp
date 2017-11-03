//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Meneses Cornejo Kevin Osmar				******//
//*************											******//
//************************************************************//
#include "Main.h"
FILE *archsal;
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

#define MAX_FRAMES 60
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float angCodo;		//Variable para codo
	float angCodoInc;		//Variable para codo
	float angHombro;		//Variable para hombro
	float angHombroInc;		//Variable para Incremento hombro
	float angMano;		//Variable para mano
	float angManoInc;		//Variable para Incremento mano
	float angPulgar1;
	float angPulgar1Inc;
	float angPulgar2;
	float angPulgar2Inc;
	float angInd1;
	float angInd1Inc;
	float angInd2;
	float angInd2Inc;
	float angInd3;
	float angInd3Inc;
	float angMedi1;
	float angMedi1Inc;
	float angMedi2;
	float angMedi2Inc;
	float angMedi3;
	float angMedi3Inc;
	float angAnu1;
	float angAnu1Inc;
	float angAnu2;
	float angAnu2Inc;
	float angAnu3;
	float angAnu3Inc;
	float angMen1;
	float angMen1Inc;
	float angMen2;
	float angMen2Inc;
	float angMen3;
	float angMen3Inc;
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

void InitGL(void)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
														//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
														//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//NEW Iniciar variables de KeyFrames
	for (int i = 0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].angCodo = 0;
		KeyFrame[i].angHombro = 0;
		KeyFrame[i].angMano = 0;
		KeyFrame[i].angPulgar1 = 0;
		KeyFrame[i].angPulgar2 = 0;
		KeyFrame[i].angInd1 = 0;
		KeyFrame[i].angInd2 = 0;
		KeyFrame[i].angInd3 = 0;
		KeyFrame[i].angMedi1 = 0;
		KeyFrame[i].angMedi2 = 0;
		KeyFrame[i].angMedi3 = 0;
		KeyFrame[i].angMen1 = 0;
		KeyFrame[i].angMen2 = 0;
		KeyFrame[i].angMen3 = 0;
		KeyFrame[i].angAnu1 = 0;
		KeyFrame[i].angAnu2 = 0;
		KeyFrame[i].angAnu3 = 0;
	}
	//NEW//////////////////NEW//////////////////NEW///////////
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
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
void saveFrame(void)
{

	printf("frameindex %d\n", FrameIndex);
	archsal = fopen("salida.txt", "a");
	KeyFrame[FrameIndex].angCodo = angCodo;
	KeyFrame[FrameIndex].angHombro= angHombro;
	KeyFrame[FrameIndex].angMano = angMano;
	KeyFrame[FrameIndex].angPulgar1 = angPulgar1;
	KeyFrame[FrameIndex].angPulgar2 = angPulgar2;
	KeyFrame[FrameIndex].angInd1 = angInd1;
	KeyFrame[FrameIndex].angInd2 = angInd2;
	KeyFrame[FrameIndex].angInd3 = angInd3;
	KeyFrame[FrameIndex].angMedi1 = angMedi1;
	KeyFrame[FrameIndex].angMedi2 = angMedi2;
	KeyFrame[FrameIndex].angMedi3 = angMedi3;
	KeyFrame[FrameIndex].angAnu1 = angAnu1;
	KeyFrame[FrameIndex].angAnu2= angAnu2;
	KeyFrame[FrameIndex].angAnu3 = angAnu3;
	KeyFrame[FrameIndex].angMen1 = angMen1;
	KeyFrame[FrameIndex].angMen2 = angMen2;
	KeyFrame[FrameIndex].angMen3 = angMen3;
	fprintf(archsal, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", angCodo, angHombro, angMano, angPulgar1, angPulgar2, angInd1, angInd2, angInd3,
		angMedi1, angMedi2, angMedi3, angMen1, angMen2, angMen3, angAnu1, angAnu2, angAnu3);
	FrameIndex++;
	fclose(archsal);
}

void cargaEstructura() {
	int final;
	FrameIndex = 0;
	archsal = fopen("salida.txt", "r");
	final = fscanf(archsal, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", &KeyFrame[FrameIndex].angCodo,
		&KeyFrame[FrameIndex].angHombro, &KeyFrame[FrameIndex].angMano, &KeyFrame[FrameIndex].angPulgar1, &KeyFrame[FrameIndex].angPulgar2,
		&KeyFrame[FrameIndex].angInd1, &KeyFrame[FrameIndex].angInd2, &KeyFrame[FrameIndex].angInd3,
		&KeyFrame[FrameIndex].angMedi1, &KeyFrame[FrameIndex].angMedi2, &KeyFrame[FrameIndex].angMedi3,
		&KeyFrame[FrameIndex].angMen1, &KeyFrame[FrameIndex].angMen2, &KeyFrame[FrameIndex].angMen3,
		&KeyFrame[FrameIndex].angAnu1, &KeyFrame[FrameIndex].angAnu2, &KeyFrame[FrameIndex].angAnu3);
	while (final != EOF) {
		final = fscanf(archsal, "%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", &KeyFrame[FrameIndex].angCodo,
			&KeyFrame[FrameIndex].angHombro, &KeyFrame[FrameIndex].angMano, &KeyFrame[FrameIndex].angPulgar1, &KeyFrame[FrameIndex].angPulgar2,
			&KeyFrame[FrameIndex].angInd1, &KeyFrame[FrameIndex].angInd2, &KeyFrame[FrameIndex].angInd3,
			&KeyFrame[FrameIndex].angMedi1, &KeyFrame[FrameIndex].angMedi2, &KeyFrame[FrameIndex].angMedi3,
			&KeyFrame[FrameIndex].angMen1, &KeyFrame[FrameIndex].angMen2, &KeyFrame[FrameIndex].angMen3,
			&KeyFrame[FrameIndex].angAnu1, &KeyFrame[FrameIndex].angAnu2, &KeyFrame[FrameIndex].angAnu3);
		FrameIndex++;
	}
	fclose(archsal);
}
void resetElements(void)
{
	angCodo = KeyFrame[0].angCodo;
	angHombro = KeyFrame[0].angHombro;
	angMano = KeyFrame[0].angMano;
	angPulgar1 = KeyFrame[0].angPulgar1;
	angPulgar2 = KeyFrame[0].angPulgar2;
	angInd1 = KeyFrame[0].angInd1;
	angInd2 = KeyFrame[0].angInd2;
	angInd3 = KeyFrame[0].angInd3;
	angMedi1 = KeyFrame[0].angMedi1;
	angMedi2 = KeyFrame[0].angMedi3;
	angMedi3 = KeyFrame[0].angMedi3;
	angAnu1 = KeyFrame[0].angAnu1;
	angAnu2 = KeyFrame[0].angAnu2;
	angAnu3 = KeyFrame[0].angAnu3;
	angMen1 = KeyFrame[0].angMen1;
	angMen2 = KeyFrame[0].angMen2;
	angMen3 = KeyFrame[0].angMen3;
}

void interpolation(void)
{
	KeyFrame[playIndex].angCodoInc = (KeyFrame[playIndex + 1].angCodo - KeyFrame[playIndex].angCodo) / i_max_steps;
	KeyFrame[playIndex].angHombroInc= (KeyFrame[playIndex + 1].angHombro - KeyFrame[playIndex].angHombro) / i_max_steps;
	KeyFrame[playIndex].angManoInc = (KeyFrame[playIndex + 1].angMano - KeyFrame[playIndex].angMano) / i_max_steps;
	KeyFrame[playIndex].angPulgar1Inc = (KeyFrame[playIndex + 1].angPulgar1 - KeyFrame[playIndex].angPulgar1) / i_max_steps;
	KeyFrame[playIndex].angPulgar2Inc = (KeyFrame[playIndex + 1].angPulgar2 - KeyFrame[playIndex].angPulgar2) / i_max_steps;
	KeyFrame[playIndex].angInd1Inc = (KeyFrame[playIndex + 1].angInd1 - KeyFrame[playIndex].angInd1) / i_max_steps;
	KeyFrame[playIndex].angInd2Inc = (KeyFrame[playIndex + 1].angInd2 - KeyFrame[playIndex].angInd2) / i_max_steps;
	KeyFrame[playIndex].angInd3Inc = (KeyFrame[playIndex + 1].angInd3 - KeyFrame[playIndex].angInd3) / i_max_steps;
	KeyFrame[playIndex].angMedi1Inc = (KeyFrame[playIndex + 1].angMedi1 - KeyFrame[playIndex].angMedi1) / i_max_steps;
	KeyFrame[playIndex].angMedi2Inc = (KeyFrame[playIndex + 1].angMedi2 - KeyFrame[playIndex].angMedi2) / i_max_steps;
	KeyFrame[playIndex].angMedi3Inc = (KeyFrame[playIndex + 1].angMedi3 - KeyFrame[playIndex].angMedi3) / i_max_steps;
	KeyFrame[playIndex].angMen1Inc = (KeyFrame[playIndex + 1].angMen1 - KeyFrame[playIndex].angMen1) / i_max_steps;
	KeyFrame[playIndex].angMen2Inc = (KeyFrame[playIndex + 1].angMen2 - KeyFrame[playIndex].angMen2) / i_max_steps;
	KeyFrame[playIndex].angMen3Inc = (KeyFrame[playIndex + 1].angMen3 - KeyFrame[playIndex].angMen3) / i_max_steps;
	KeyFrame[playIndex].angAnu1Inc = (KeyFrame[playIndex + 1].angAnu1 - KeyFrame[playIndex].angAnu1) / i_max_steps;
	KeyFrame[playIndex].angAnu2Inc = (KeyFrame[playIndex + 1].angAnu2 - KeyFrame[playIndex].angAnu2) / i_max_steps;
	KeyFrame[playIndex].angAnu3Inc = (KeyFrame[playIndex + 1].angAnu3 - KeyFrame[playIndex].angAnu3) / i_max_steps;
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleX * 50, 1.0, 0.0, 0.0);
	glRotatef(angleY * 50, 0.0, 1.0, 0.0);
	//Poner Código Aquí.
	
	//brazo 
	glPushMatrix();
		glTranslated(2.0, 0.0, 7.0);
		glRotatef(90, 0.0, 0.0, 1.0);
		glRotatef(180, 1.0, 0.0, 0.0);
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

	

	glutSwapBuffers();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);


	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void animacion()
{
	
	//Movimiento de la mano
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			angCodo += KeyFrame[playIndex].angCodoInc;
			angHombro += KeyFrame[playIndex].angHombroInc;
			angMano += KeyFrame[playIndex].angManoInc;
			angPulgar1 += KeyFrame[playIndex].angPulgar1Inc;
			angPulgar2 += KeyFrame[playIndex].angPulgar2Inc;
			angInd1 += KeyFrame[playIndex].angInd1Inc;
			angInd2 += KeyFrame[playIndex].angInd2Inc;
			angInd3 += KeyFrame[playIndex].angInd3Inc;
			angMedi1 += KeyFrame[playIndex].angMedi1Inc;
			angMedi2 += KeyFrame[playIndex].angMedi2Inc;
			angMedi3 += KeyFrame[playIndex].angMedi3Inc;
			angMen1 += KeyFrame[playIndex].angMen1Inc;
			angMen2 += KeyFrame[playIndex].angMen2Inc;
			angMen3 += KeyFrame[playIndex].angMen3Inc;
			angAnu1 += KeyFrame[playIndex].angAnu1Inc;
			angAnu2 += KeyFrame[playIndex].angAnu2Inc;
			angAnu3 += KeyFrame[playIndex].angAnu3Inc;
			i_curr_steps++;
		}

	}


	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'r':
		if (angMen3 < 90)
			angMen3 += 0.5f;
		break;
	case 'R':
		if (angMen3 >= 0)
			angMen3 -= 0.5f;
		break;
	case 't':
		if (angMen2 < 90)
			angMen2 += 0.5f;
		break;
	case 'T':
		if (angMen2 >= 0)
			angMen2 -= 0.5f;
		break;
	case 'y':
		if (angMen1 < 90)
			angMen1 += 0.5f;
		break;
	case 'Y':
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
	case 'x':
		if (angMedi2<90)
			angMedi2 += 0.5f;
		break;
	case 'X':
		if (angMedi2 >= 0)
			angMedi2 -= 0.5f;
		break;
	case 'z':
		if (angMedi1<90)
			angMedi1 += 0.5f;
		break;
	case 'Z':
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
		if (angInd1 >= 0)
			angInd1 -= 0.5f;
		break;
	case 'F':
		if (angPulgar2<0)
			angPulgar2 += 0.5f;
		break;
	case 'f':
			if (angPulgar2 >= -90)
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
	case 'o':
		if (angMano<90)
			angMano += 0.5f;
		break;
	case 'O':
		if (angMano >= 0)
			angMano -= 0.5f;
		break;
	
		
	case 'i':
		if (angCodo<90)
			angCodo += 0.5f;
		break;
	case 'I':
		if (angCodo >= 0)
			angCodo -= 0.5f;
		break;
		
	case 'u':
		if (angHombro<90)
			angHombro += 0.5f;
		break;
	case 'U':
		if (angHombro >= -90)
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
	case 'k':		//
	case 'K':
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}

		break;

	case 'l':
	case 'L':
		if (play == false && (FrameIndex>1))
		{

			resetElements();
			//First Interpolation				
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
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

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex >1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}
void menu(int id)
{

}
int main(int argc, char** argv)   // Main Function
{
	int submenu;

	glutInit(&argc, argv); // Inicializamos OpenGL
						   //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 11"); // Nombre de la Ventana
	InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  archsal = fopen("salida.txt", "r");
  if(archsal != NULL)
  cargaEstructura();
  glutIdleFunc		  ( animacion );
  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);
	glutMainLoop();          // 

	return 0;
}