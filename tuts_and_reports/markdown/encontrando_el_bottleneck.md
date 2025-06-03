# Encontrando el BottleNeck

Para poder encontrar el cuello de botella, se han asumido dos afirmaciones, que serán puestas a prueba para tratar de paliar con los problemas de rendimiento del sistema.

## El problema está en el hardware

Se ha asumido que son limitaciones de rendimiento de la propia raspberry pico, por lo que se probará en una raspberry pi 3 con una [debian 12 para 3B+](https://raspi.debian.net/tested-images/).

### Kernel RT en Raspberry Pi 3

Instalación del kernel en la Raspberry Pi 3 tras la installación de Debian 12
```bash
sudo apt install linux-image-rt-arm64
```

Después se ha usado la rama `pico-neuron-not-pico`, que es una versión modificada del programa que no usa las herramientas destinadas a que sea ejecutado en una Raspberry Pico, por lo que usa los threads realtime de Preempt_RT.

## El problema está en el software


### Pico sin escritura

Se ha 800 segundos simulados sin escritura. Ha tardado 31 segundos reales.

### Pico con escritura

Se ha 800 segundos simulados con escritura. Ha tardado 615 segundos reales.

### Solución

Un core lógico y otro de escritura, el lógico solo manda datos una vez han sido consumidos por el de escritura.


