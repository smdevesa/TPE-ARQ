# Trabajo Práctico Especial - Arquitectura de Computadoras - 1C 2024
***
## Integrantes:
- Nicolás Ezequiel Revale (64227)
- Santiago Manuel Devesa (64223)
- Tiziano Fuchinecco (64191)
- Tomás Rafael Balboa Koolen (64237)
***
## Manual de usuario

### Requerimientos

- Tener instalado el programa `make`
- Tener instalado el programa `gcc`
- Tener instalado el programa `nasm`
- Tener instalado el programa `docker`
- Tener instalado el programa `qemu`

***
  
### Compilación

1. Ejecutar el comando: `docker pull agodio/itba-so:1.0`
2. Clonar el repositorio: `git clone git@github.com:smdevesa/TPE-ARQ.git`
3. En el directorio del repositorio, ejecutar el comando: `docker run -v ${PWD}:/root --security-opt seccomp:unconfined -ti agodio/itba-so:1.0`
4. Dentro del contenedor, ejecutar los siguientes comandos:
    - `cd /root/Toolchain`
    - `make all`
    - `cd /root`
    - `make all`
5. Salir del contenedor con el comando `exit`

***

### Ejecución

1. Ejecutar el archivo `run.sh` con el comando: `./run.sh` en Linux o macOS.
Si se desea ejecutar con sonido, ejecutar el archivo `runSound.sh` con el comando: `./runSound.sh` en Linux o macOS.

***

### Uso de Shell

Es posible utilizar la shell como un intérprete de comandos. 
Si bien se puede escribir hasta que se llene la pantalla de caracteres, 
sólo los primeros 29 caracteres serán interpretados. 
Para ejecutar un comando, simplemente escribirlo y presionar la tecla `ENTER`.\
Los comandos disponibles son los siguientes:

- `help`: Muestra un mensaje de ayuda con los comandos disponibles.
- `clear`: Limpia la pantalla.
- `exit`: Cierra la shell terminando con la ejecución.
- `date`: Muestra la fecha y hora actual en GMT.
- `fontscale <argumento>`: Cambia el tamaño de la fuente de la shell. 
    Parámetros: tamaño de la fuente (1 a 3).
- `inforeg`: Muestra los valores de los registros de propósito general. Antes de
    ejecutar este comando, se deben guardar los valores de los registros
    utilizando la combinación de teclas `Ctrl + R`.
- `eliminator`: Ejecuta un juego similar al juego de la película "TRON".\
    Para moverse, utilizar las teclas `W`, `A`, `S` y `D`.\
    En caso de jugar de a dos jugadores, el segundo jugador se moverá con las teclas `I`, `J`, `K` y `L`.\
    Al terminar una partida se puede volver a jugar con la tecla `SPACE` o salir con la tecla `ESC`.
- `exception <argumento>`: Prueba las excepciones de la CPU.\
    Parámetros: tipo de excepción. Las excepciones soportadas son: `zero` (división por cero) y `invalidOpcode` (código de operación inválido).

***

#### System Calls

A continuación se detallan las system calls implementadas y sus respectivos parámetros:

| Nombre          | %rax | %rdi              | %rsi                | %rdx         | %rcx               | %r8               |
|-----------------|------|-------------------|---------------------|--------------|--------------------|-------------------|
| read            | 0    | int fd            | char * buffer       | int count    | uint32_t hexColor  | -                 |
| write           | 1    | int fd            | const char * buffer | int count    | -                  | -                 |
| drawRectangle   | 2    | uint32_t hexColor | uint64_t x          | uint64_t y   | uint64_t width     | uint64_t height   |
| clearScreen     | 3    | -                 | -                   | -            | -                  | -                 |
| getCoords       | 4    | -                 | -                   | -            | -                  | -                 |
| getScreenInfo   | 5    | -                 | -                   | -            | -                  | -                 |
| getFontInfo     | 6    | -                 | -                   | -            | -                  | -                 |
| getTime         | 7    | uint64_t param    | -                   | -            | -                  | -                 |
| setFontScale    | 8    | uint64_t scale    | -                   | -            | -                  | -                 |
| getRegisters    | 9    | uint64_t * regs   | -                   | -            | -                  | -                 |
| sleep           | 10   | uint64_t millis   | -                   | -            | -                  | -                 |
| playSound       | 11   | uint64_t freq     | uint64_t millis     | -            | -                  | -                 |

Explicaciones de las system calls:
- `read`: Lee `count` bytes del archivo `fd` y los guarda en el buffer `buffer`.
- `write`: Escribe `count` bytes del buffer `buffer` en el archivo `fd` con el color `hexColor`.
- `drawRectangle`: Dibuja un rectángulo en la pantalla con el color `hexColor`, en la posición `(x, y)` y con las dimensiones `width` y `height`.
- `clearScreen`: Limpia la pantalla.
- `getCoords`: Obtiene las coordenadas del cursor. Devuelve por `rax` un valor de 64 bits donde los primeros 32 bits representan la coordenada `x` y los siguientes 32 bits representan la coordenada `y`.
- `getScreenInfo`: Obtiene la información de la pantalla. Devuelve por `rax` un valor de 64 bits donde los primeros 32 bits el ancho en píxeles y los siguientes 32 bits representan el alto en píxeles.
- `getFontInfo`: Obtiene la información de la fuente. Devuelve por `rax` un valor de 64 bits donde los primeros 32 bits representan el ancho de la fuente y los siguientes 32 bits representan el alto de la fuente.
- `getTime`: Lee los datos de fecha y hora del RTC.
- `setFontScale`: Cambia el tamaño de la fuente de la shell.
- `getRegisters`: Obtiene los valores de los registros de propósito general y los guarda en regs. Antes de ejecutar esta syscall se deben guardar los valores de los registros utilizando la combinación de teclas `Ctrl + R`.
- `sleep`: Pausa la ejecución del programa por `millis` milisegundos.
- `playSound`: Reproduce un sonido de frecuencia `freq` durante `millis` milisegundos.


