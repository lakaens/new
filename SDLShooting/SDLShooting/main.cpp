#include<iostream>
#include <SDL.h>
//#include<SDL_image.h>
#define NUMBULLETS 4 //numero de bales que es poden disparar.



int main(int argc, char *args[]) {
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *BMP = NULL;
	SDL_Texture *texture = NULL;


	
	int posX = 100, posY = 100, width = 1280, height = 720;  //declaro posición y tamaño de la ventana que creo.

	SDL_Rect Obama;
	Obama.x = 0;
	Obama.y = 0;
	Obama.w = width;
	Obama.h = height;

	SDL_Init(SDL_INIT_EVERYTHING);  //inicio SDL.	

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {//Estas 2 lineas sirven para comprobar si ha fallado y en qué ha fallado.
		std::cout << "SDL could not initialise! SDL Error: " << SDL_GetError() << std::endl;
	}

	window = SDL_CreateWindow("Hello world", posX, posY, width, height, SDL_WINDOW_SHOWN);//creo una ventana(window), primero pongo el título(Hello world), despues la posicion y por ultimo el tamaño.(Consultar que es el 0).
	if (window != 0) {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	}
	else {//Si la ventana no se ha podido crear , me dice qué fallo es el que ha surgido.
		std::cout << "Could not create a window: %s\n" << SDL_GetError() << std::endl;
		return 1;
	}

	BMP = SDL_LoadBMP("obama.bmp");
	if (BMP == NULL) 
	{

		std::cout << "Couldn't load image!" << std::endl;

	}

	texture = SDL_CreateTextureFromSurface(renderer, BMP);

	SDL_RenderCopy(renderer, texture, NULL, &Obama );

	SDL_Rect fondorect;//creo fondo
	fondorect.x = posX;
	fondorect.y = posY;
	fondorect.w = width;
	fondorect.h = height; 

	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);//defino el color del renderer(en este caso será rojo)
	//SDL_RenderClear(renderer);
	
	SDL_Rect rectangulo;//en estas líneas defino la posición y el tamaño del rectangulo que voy a crear.
	rectangulo.x = posX;
	rectangulo.y = posY;
	rectangulo.w = 50;
	rectangulo.h = 50;

	SDL_Rect bullet[NUMBULLETS];//en estas líneas defino la posición y el tamaño de la bala que voy a crear. Es un array porque tenemos mas de una bala.

	SDL_Event event;
	
	bool running = true;//declaro variables booleanas para el funcionamiento y las teclas(true=funcionando/false=sin funcionar)
	bool right = false;
	bool left = false;
	bool up = false;
	bool down = false;
	bool space = false;//tecla para disparar.
	
	int contador = 0;
	
	while (running) {//mientras el juego esté ejecuando.
		
		if (SDL_PollEvent(&event)) {//entramos en un bucle sin fin, debemos ponerle nosotros el fin.	
			
			if (event.type == SDL_KEYDOWN) {//si se detecta que estamos apretando una tecla.
				
				switch (event.key.keysym.sym) {//switch de las teclas que queremos definir.
				case SDLK_ESCAPE://tecla escape
					running = false; break;//si detecta que se aprieta running deja de funcionar, por lo tanto salimos del loop y se cierra el juego.
				case SDLK_UP://flecha arriba
					up = true;
					break;
				case SDLK_DOWN://flecha abajo		
					down = true;
					break;
				case SDLK_LEFT:	//felcha izquierda			
					left = true;
					break;
				case SDLK_RIGHT://flecha derecha					
					right = true;
					break;
				case SDLK_SPACE://espacio
					space = true;
					bullet[contador].x = rectangulo.x;//Ponemos esto para que la posición origen  de la bala esté en el retcángulo.
					bullet[contador].y = rectangulo.y;
					break;
				default: break;
				}
			}
			
			else if (event.type == SDL_KEYUP) {//si detecta que no se pulsan las teclas
				
				switch (event.key.keysym.sym) {//definimos que telcas
				case SDLK_ESCAPE:
					running = true; 
					break;
				case SDLK_UP:
					up = false;
					break;
				case SDLK_LEFT:
					left = false; 
					break;
				case SDLK_RIGHT:
					right = false; 
					break;
				case SDLK_DOWN:
					down = false; 
					break;
				//case SDLK_SPACE:
					//space = false;
					//break;
				default: break;
				}
			}
		}

		if (rectangulo.y != 0&&up) rectangulo.y -= 5;//definimos los limites de movimiento y hacia donde se mueve ne cada caso.
		if (rectangulo.y != 670&&down)rectangulo.y += 5;
		if (rectangulo.x != 0&&left)rectangulo.x -= 5;
		if (rectangulo.x != 1230&&right)rectangulo.x += 5;

		SDL_RenderCopy(renderer, texture, NULL, &Obama);
		SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);//mientras el juego este en ejecución(running) que pinte sin parar.
		//SDL_RenderClear(renderer);
		
		
		if (space==true)
		{//si el espacio está apretado
			space = false;
			bullet[contador].x = rectangulo.x;//asignamos la posición origen de la bala a la del rectangulo para que la bala salga siempre desde donde esté el rectangulo.
			bullet[contador].y = rectangulo.y;
			bullet[contador].w = 40;
			bullet[contador].h = 2;
			contador++;
			if (contador == NUMBULLETS)//queremos que solo dispare dos balas, decimos que cuando dispare la segunda, coja ésta para que sea la tercera.
			{
				contador = 0;
			}
		}
		
		for (int i = 0; i < NUMBULLETS; i++)//for que pinta y mueve la bala.
		{
			bullet[i].x += 20;
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderFillRect(renderer, &bullet[i]); 

		}
	
		
		SDL_RenderCopy(renderer, texture, NULL, &Obama);
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);//mientras el juego este en ejecución(running) que pinte el cuadrado sin parar.
		SDL_RenderFillRect(renderer, &rectangulo);
		SDL_RenderPresent(renderer);

	}

	
	
	SDL_Quit();


	return EXIT_SUCCESS;
}



/*int main(int argc, char*argv[])
{
	SDL_Event event;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;
	
	SDL_Init(SDL_INIT_EVERYTHING);

	
	
	window = SDL_CreateWindow("SDL2IMAGEPLAYER", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	image = SDL_LoadBMP("/sdllfondo.bmp");
	texture = SDL_CreateTextureFromSurface(renderer, image);

	bool running = true;

	while (running) 
	{
		if (SDL_PollEvent(&event))
		{

			if (event.type == SDL_KEYDOWN)
			{

				switch (event.key.keysym.sym) 
				{

				case SDLK_ESCAPE:
					running = false;
					break;
				default: break;
				
				}

			}

			SDL_RenderCopy(renderer, texture, NULL, NULL);
			SDL_RenderPresent(renderer);

		}
	}
	
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	
	SDL_Quit();
	
	return EXIT_SUCCESS;
}*/
