# Instalación de Ubuntu RT

Por Sergio Hidalgo

## Índice
  - [Introducción](#introducción)
  - [Requisitos](#requisitos)
  - [Instalación](#instalación)
    - [Grabar la imagen en el usb](#grabar-la-imagen-en-el-usb)
    - [Seleccionarlo en la BIOS](#seleccionarlo-en-la-BIOS)
    - [Seguir los pasos](#seguir-los-pasos)
    - [Instalar librerías necesarias](#instalar-librerías-necesarias)
  - [Instalar Preempt RT](#instalar-preempt-rt)
  - [Comprobar el kernel](#comprobar-el-kernel)
  - [Descargar RTHybrid](#descargar-rthybrid)
  - [Descargar drivers Comedi](#descargar-drivers-comedi)
  - [Descargar otras librerias](#descargar-otras-librerias)


## Introducción
En este documento se expone paso a paso como instalar Ubuntu RT

## Requisitos
- Una imagen de Ubuntu 24.04.2 LTS o superior
- Un USB de 8GB o más


## Instalación

### Grabar la imagen en el usb

### Seleccionarlo en la BIOS

### Seguir los pasos

### Instalar librerías necesarias
- wget
- make
- gcc
- git
- autoconf
- dkms


## Instalar Preempt RT

### Crear cuenta en Ubuntu One

### Ubuntu Pro

### Añadir el sistema a la cuenta

```bash
sudo pro attach {token}
```

Donde $\{token\}$ es el token de activación de la cuenta de Ubuntu pro.

### Ejecutar los siguientes comandos

```bash
sudo apt update && sudo apt install ubuntu-advantage-tools
```

Para actualizar e instalar las herramientas profesionales de ubuntu

```bash
sudo pro enable realtime-kernel --access-only
```

Para acceder el repositorio realtime de Ubuntu (necesita confirmación por terminal).

```bash
sudo apt install ubuntu-realtime -y
```
Para instalar y activar el kernel realtime de ubuntu.

Tras esto, se debe reiniciar el ordenador


## Comprobar el kernel

Con el siguiente comando se puede comprobar el kernel y su información, debe aparecer `PREEMPT_RT` en lugar de `PREEMPT_DYNAMIC`

```bash
uname -a
```


## Descargar drivers Comedi

```bash
git clone https://github.com/Linux-Comedi/comedi.git
cd comedi
./autogen.sh
cd ..
sudo dkms add ./comedi
sudo depmod -a
sudo apt install libcomedi0 libcomedi-dev -y
```
## Descargar otras librerias
- qtmultimedia5-dev
- qtbase5-dev
- qtchooser
- qt5-qmake
- qtbase5-dev-tools
- libxml2
- libxml2-dev

## Descargar RTHybrid
[RTHybrid Github](https://github.com/GNB-UAM/RTHybrid)


```bash
git clone https://github.com/GNB-UAM/RTHybrid.git
cd RTHybrid
sudo sh compile.sh
```


## Benchmarks
[Benchmarks Github](https://github.com/RoyVII/Latency_tests)