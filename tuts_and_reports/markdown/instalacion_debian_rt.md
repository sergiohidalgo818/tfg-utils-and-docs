
# Tutorial de preparación e instalación de RTXI para Debian con Preempt-RT

## Instalación de Debian

Instalar debian desde un USB.

## Instalación de preempt-rt

Una vez instalado, seguir los siguientes pasos.

### Versión del kernel

```bash
uname -r
```

En este caso es `6.1.0-34-amd64`, por lo  que `version=6.1.0.34`. Esto no es estrictamente necesario, pero sí recomendable.

### Instalar la imagen de dicha versión del kernel realtime

```bash
sudo apt install linux-image-$version-rt-amd64
```

### Instalar los headers de dicha versión del kernel realtime

```bash
sudo apt install linux-headers-$version-rt-amd64
```


## Instalación de paquetes necesarios

```bash
sudo apt install git make gcc autoconf dkms -y
```

## Drivers National Instruments

### Drivers Ubutu

Los [ drivers oficiales ](https://www.ni.com/es/support/downloads/drivers/download.ni-linux-device-drivers.html) para placas de National Instruments. Para ello iniciar sesión y descargar, tras esto descomprimir el fichero.

En este caso es  `NILinux2025Q2DeviceDrivers.zip`

```bash
unzip NILinux2025Q2DeviceDrivers.zip
```

Y se creará un directorio con los distintos drivers, nosotros cogeremos el .deb para ubuntu (aun que estemos en debian). La versión stream se actualiza con mayor frecuencia, así que escogeremos la otra.

```bash
sudo dpkg -i ./ni-ubuntu2404-drivers-2025Q2.deb
```
Tras esto hacer

```bash
sudo apt update && sudo apt upgrade
```


### NI-DAQmx

Si el paso anterior ha ido bien, se podrán instalar los drivers ni-daqmax a través de apt.


```bash
sudo apt install ni-daqmx
```

Y reiniciar (para asegurar que se cargan bien los drivers).

```bash
sudo reboot
```

## RTXI

Descargar la versión [ modificada de RTXI ]() para preempt-rt

```bash
git clone https://github.com/sergiohidalgo818/rtxi
```

Una vez hecho esto, cambiar a la rama `preempt-rt`

```bash
git checkout preempt-rt
```

### Dependencias

Instalar las dependencias

```bash
sudo ./scripts/install_dependencies.sh
```


### RTXI - Preempt-RT

Instalar RTXI, para ello, seleccionar la opción `preempt-rt`.

```bash
./scripts/install_rtxi.sh
```



## Pruebas de rendimiento

En la página oficial de RTXI, realizan una prueba de rendimiento, seleccionando bajo la pestaña **System**: *Data Recorder*, *RT Benchmarks* y *Control Panel*, dentro de este último, debería aparecer el nombre de la tarjeta, driver o ranura PCI asociada a la tarjeta de NI.

### System Control Panel

En periodo seleciona $us$ y cambia su valor a $100$

### Data Recorder

En **Block**, selecionar *RT Benchmarks*. Habrá que añadir en channel los datos a revisar, en este caso vamos a guardar todo lo que no sean máximos.
