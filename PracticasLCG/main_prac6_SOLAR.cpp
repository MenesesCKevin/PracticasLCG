//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Meneses Cornejo Kevin Osmar			******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0; 
int tierra = 0;
int luna = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
 

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };


GLfloat mercurio_diffuseS[] = { 1.0, 0.0, 0.3, 1.0 };				// Object Color main
GLfloat mercurio_specularS[] = { 0.0, 1.0, 0.0, 1.0 };				// Specular color
GLfloat mercurio_shininessS[] = { 100.0 };							// 1 to greatest

GLfloat venus_diffuseS[] = { 0.7, 0.2, 0.0, 1.0 };				// Object Color main
GLfloat venus_specularS[] = { 0.0, 1.0, 1.0, 1.0 };				// Specular color
GLfloat venus_shininessS[] = { 100.0 };							// 1 to greatest

GLfloat luna_diffuseS[] = { 1.0, 1.0, 1.0, 1.0 };				// Object Color main
GLfloat luna_specularS[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular color
GLfloat luna_shininessS[] = { 100.0 };							// 1 to greatest

GLfloat jupiter_diffuseS[] = { 0.6, 0.0, 0.4, 1.0 };				// Object Color main
GLfloat jupiter_specularS[] = { 0.5, 1.0, 0.0, 1.0 };				// Specular color
GLfloat jupiter_shininessS[] = { 100.0 };							// 1 to greatest

GLfloat saturno_diffuseS[] = { 0.3, 0.7, 0.8 };				// Object Color main
GLfloat saturno_specularS[] = { 0.0, 1.0, 0.5, 1.0 };				// Specular color
GLfloat saturno_shininessS[] = { 100.0 };							// 1 to greatest

GLfloat anillo_diffuseS[] = { 0.8, 0.8, 0.8, 1.0 };				// Object Color main
GLfloat anillo_specularS[] = { 0.7, 0.6, 0.5, 1.0 };				// Specular color
GLfloat anillo_shininessS[] = { 100.0 };							// 1 to greatest

GLfloat urano_diffuseS[] = { 0.7, 0.6, 0.5 };				// Object Color main
GLfloat urano_specularS[] = { 0.6, 1.0, 0.5, 1.0 };				// Specular color
GLfloat urano_shininessS[] = { 100.0 };							// 1 to greatest

GLfloat neptuno_diffuseS[] = { 0.5, 0.5, 0.4 };				// Object Color main
GLfloat neptuno_specularS[] = { 0.5, 1.0, 0.5, 1.0 };				// Specular color
GLfloat neptuno_shininessS[] = { 100.0 };							// 1 to greatest

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	/*Esto inicia la luz*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);



}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition); //
	glDisable(GL_LIGHTING);
	glutSolidSphere(2, 20, 20);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	//mercurio
	
	glPushMatrix();
		glRotatef(mercurio, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotatef(mercurio-1, 0.0, 1.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(3.0, 0.2, 0.2);
			glRotatef(mercurio-3, 0.0, -1.0, 0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mercurio_diffuseS);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mercurio_specularS);
			glMaterialfv(GL_FRONT, GL_SHININESS, mercurio_shininessS);
			glutSolidSphere(0.3, 10, 10);
		glPopMatrix();
		glPopMatrix();

	//venus
	glPushMatrix();
		glRotatef(venus, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotatef(venus, 0.0, 1.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(4.0, 0.2, 0.2);
			glRotatef(venus- 3, 0.0, -1.0, 0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, venus_diffuseS);
			glMaterialfv(GL_FRONT, GL_SPECULAR, venus_specularS);
			glMaterialfv(GL_FRONT, GL_SHININESS, venus_shininessS);
			glutSolidSphere(0.3, 10, 10);
		glPopMatrix();
	glPopMatrix();
	
	//tierra
	glPushMatrix();
		glRotatef(tierra, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotatef(tierra, 0.0, 1.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(6, 0.2, 0.2);
			glRotatef(tierra-3, 0.0, 1.0, 0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
			glutSolidSphere(0.6, 10, 10);
			
			//luna
			glRotatef(luna, 0.0, -1.0, 0.0);
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
				glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
				glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
				glTranslatef(1.0,0.0, 0.2);
				glRotatef(luna+2, 0.0,- 1.0, 0.0);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
			glPopMatrix();
	glPopMatrix();
	
	//marte
	glPushMatrix();
	
		glRotatef(marte, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotatef(marte-6, 0.0, 1.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(8.5, 0.2, 0.2);
			glRotatef(marte- 3, 0.0, -1.0, 0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
			glutSolidSphere(0.36, 10, 10);
			//luna
			glRotatef(luna, 0.0, -1.0, 0.0);
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
				glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
				glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
				glTranslatef(0.6, 0.2, 0.2);
				glRotatef(luna + 2, 0.0, -1.0, 0.0);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
			//luna
			glRotatef(luna, 0.0, -1.0, 0.0);
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
				glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
				glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
				glTranslatef(0.6, -0.2, 0.2);
				glRotatef(luna + 2, 0.0, -1.0, 0.0);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	
	//jupiter
	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, jupiter_diffuseS);
		glMaterialfv(GL_FRONT, GL_SPECULAR, jupiter_specularS);
		glMaterialfv(GL_FRONT, GL_SHININESS, jupiter_shininessS);
		glRotatef(jupiter, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotatef(jupiter, 0.0, 1.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(14, 0.2, 0.2);
			glRotatef(jupiter-2, 0.0, -1.0, 0.0);
			glutSolidSphere(2, 10, 10);
		//luna
		glRotatef(luna-1, 0.0, -1.0, 0.0);
			glPushMatrix();
			glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
			glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
			glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
			glTranslatef(2.5, 0.5, 0.2);
			glRotatef(luna, 0.0, -1.0, 0.0);
			glutSolidSphere(0.2, 10, 10);
		glPopMatrix();
		//luna
		glRotatef(luna-2, 0.0, -1.0, 0.0);
		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
			glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
			glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
			glTranslatef(2.5, 0.0, 0.2);
			glRotatef(luna, 0.0, -1.0, 0.0);
			glutSolidSphere(0.2, 10, 10);
		glPopMatrix();
		//luna
		glRotatef(luna-2, 0.0, -1.0, 0.0);
		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
			glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
			glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
			glTranslatef(2.5, -0.5, 0.2);
			glRotatef(luna, 0.0, -1.0, 0.0);
			glutSolidSphere(0.2, 10, 10);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	
	//saturno
	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, saturno_diffuseS);
		glMaterialfv(GL_FRONT, GL_SPECULAR, saturno_specularS);
		glMaterialfv(GL_FRONT, GL_SHININESS, saturno_shininessS);
		glRotatef(saturno, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotatef(saturno, 0.0, 1.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(19, 0.2, 0.2);
			glRotatef(saturno, 0.0, 1.0, 0.0);
			glutSolidSphere(0.3, 10, 10);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, anillo_diffuseS);
			glMaterialfv(GL_FRONT, GL_SPECULAR, anillo_specularS);
			glMaterialfv(GL_FRONT, GL_SHININESS, anillo_shininessS);;
			glPushMatrix();
				glRotated(90, 1.0, 0.0, 0.0);
				glutSolidTorus(0.11, 0.7, 10.0, 10.0);
			glPopMatrix();
			//luna
			glRotatef(luna - 2, 0.0, -1.0, 0.0);
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
				glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
				glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);;
				glTranslatef(1.0, 0.3, 0.2);
				glRotatef(luna, 0.0, -1.0, 0.0);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
			//luna
			glRotatef(luna-2, 0.0, -1.0, 0.0);
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
				glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
				glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
				glTranslatef(1.0, -0.3, 0.2);
				glRotatef(luna, 0.0, -1.0, 0.0);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
			glPopMatrix();
	glPopMatrix();
	
	//urano
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, urano_diffuseS);
	glMaterialfv(GL_FRONT, GL_SPECULAR, urano_specularS);
	glMaterialfv(GL_FRONT, GL_SHININESS, urano_shininessS);
	glRotatef(marte, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotatef(urano-6, 0.0, 1.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(24, 0.2, 0.2);
			glRotatef(urano- 3, 0.0, -1.0, 0.0);
			glutSolidSphere(0.9, 10, 10);
			//luna
			glRotatef(urano, 0.0, -1.0, 0.0);
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
				glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
				glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
				glTranslatef(2.0, 0.4, 0.2);
				glRotatef(luna + 2, 0.0, -1.0, 0.0);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
			//luna
			glRotatef(luna, 0.0, -1.0, 0.0);
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
				glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
				glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
				glTranslatef(2.0, -0.4, 0.2);
				glRotatef(luna + 2, 0.0, -1.0, 0.0);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	
	//neptuno
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, neptuno_diffuseS);
	glMaterialfv(GL_FRONT, GL_SPECULAR, neptuno_specularS);
	glMaterialfv(GL_FRONT, GL_SHININESS, neptuno_shininessS);
	glRotatef(neptuno, 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotatef(neptuno-6, 0.0, 1.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(29, 0.2, 0.2);
			glRotatef(neptuno- 3, 0.0, -1.0, 0.0);
			glutSolidSphere(0.7, 10, 10);
			//luna
			glRotatef(luna, 0.0, -1.0, 0.0);
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
				glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
				glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
				glTranslatef(0.9, 0.2, 0.2);
				glRotatef(luna + 2, 0.0, -1.0, 0.0);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
			//luna
			glRotatef(luna, 0.0, -1.0, 0.0);
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, luna_diffuseS);
				glMaterialfv(GL_FRONT, GL_SPECULAR, luna_specularS);
				glMaterialfv(GL_FRONT, GL_SHININESS, luna_shininessS);
				glTranslatef(0.9, -0.2, 0.2);
				glRotatef(luna + 2, 0.0, -1.0, 0.0);
				glutSolidSphere(0.2, 10, 10);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
		mercurio = (mercurio - 8) % 360;
		dwLastUpdateTime = dwCurrentTime;
		venus = (venus - 7) % 360;
		dwLastUpdateTime = dwCurrentTime;
		tierra = (tierra - 6) % 360;
		dwLastUpdateTime = dwCurrentTime;
		luna = (luna - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;
		marte = (marte - 6) % 360;
		dwLastUpdateTime = dwCurrentTime;
		jupiter = (jupiter - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;
		saturno = (saturno - 3) % 360;
		dwLastUpdateTime = dwCurrentTime;
		urano = (urano - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
		neptuno = (neptuno - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
		
	}

	glutPostRedisplay(); //vuelvo a dibujar
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
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
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);   //Manda a llamar a la animacion
	glutMainLoop();          // 

	return 0;
}