*Este proyecto ha sido creado como parte del currículo de 42 por bsiguenc.* 

# Descripción

El proyecto consiste en la creación de un programa que enseña el manejo de hilos (threads) y mutex. Consiste en crear una seríe de filósofos (hilos) que se encuentran sentados en una mesa redonda para comer, de forma que el primer filósofo este al lado del siguiente y al lado del último filósofo y asi sucesivamente. En la mesa habrá tantos tenedores como filósofos.

Cada **filósofo** debe de comer, pensar y dormir. Solo se puede realizar una cosa a la vez.

Para que un filósofo coma debe de coger el tenedor de ambos lados y los que no, deberán de esperar a que terminen los que tienen tenedores. En el momento en el que un filósofo termina de comer empezará a dormir directamente y cuando se despierte empezará a pensar de nuevo (estado intermedio a cuando no tiene tenedores).

La simulación se detiene en el momento en el que un filósofo muere de inanición.

Todos los filósofos deben comer y deben tratar de evitar morir. Los filósofos no hablan entre ellos y no saben si algun otro va a morir.

# Instrucciones

## Instalación
## Compilación
## Ejecución

# Recursos

*Todo lo posteriormente citado es una recopilación de donde he obtenido la información para el desarrollo del proyecto.*

* Manejo de **ReadMe**: [Docu Git](https://docs.github.com/es/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

* Información acerca de Pthreads y Mutex:
	* [Link1](https://www.linkedin.com/advice/1/how-can-you-use-pthreads-create-multithreaded?lang=es)



