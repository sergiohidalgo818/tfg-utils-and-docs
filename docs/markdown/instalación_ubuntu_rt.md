# Instalación de Ubuntu RT

Por Sergio Hidalgo

## Índice

- [Introducción](#introducción)
- [Requisitos](#requisitos)
- [Preparación de la imagen](#preparación-de-la-imagen)
  - [Grabar la imagen en el usb](#grabar-la-imagen-en-el-usb)
  - [Seleccionar el USB en la BIOS](#seleccionar-el-usb-en-la-bios)
  - [Seguir los pasos](#seguir-los-pasos)
- [Instalar los siguientes paquetes](#instalar-los-siguientes-paquetes)
- [Instalar Preempt RT](#instalar-preempt-rt)
  - [Crear cuenta en Ubuntu One](#crear-cuenta-en-ubuntu-one) 
  - [Obtener Ubuntu Pro](#obtener-ubuntu-pro) 
  - [Añadir el sistema a la cuenta](#añadir-el-sistema-a-la-cuenta) 
  - [Instalar el kernel realtime](#instalar-el-kernel-realtime) 
  - [Comprobar el kernel](#comprobar-el-kernel)
- [RTHybrid](#rthybrid)
  - [Descargar dependencias](#descargar-dependencias)
  - [Descargar drivers Comedi](#descargar-drivers-comedi)
  - [Descargar RTHybrid](#descargar-rthybrid)

## Introducción

En este documento se expone paso a paso como instalar Ubuntu RT

## Requisitos

- Una imagen de Ubuntu 24.04.2 LTS o superior
- Un USB de 8GB o más

## Preparación de la imagen

### Grabar la imagen en el usb

Se puede grabar la imagen con aplicaciones como [Rufus](https://rufus.ie/) o
[BaelenaEtcher](https://etcher.balena.io/).

### Seleccionar el USB en la BIOS

Entrar en la BIOS presionando una tecla especifica durante el arranque (la tecla
depende del fabricante).

### Seguir los pasos

Seguir los pasos del instalador de Ubuntu.

## Instalar los siguientes paquetes

Una vez instalado, instalar los siguientes paquetes:

- git
- make
- gcc
- autoconf
- dkms

Esto se puede hacer con el siguiente comando

```bash
sudo apt install git make gcc autoconf dkms -y
```

## Instalar Preempt RT

En las nuevas versiones de Ubuntu, esta instalación es muy sencilla. Hace falta
una cuenta _Ubuntu Pro_, pero esta es gratis para activar hasta 5 máquinas
simultáneas con una sola cuenta. A continuación se exponen los pasos a realizar
para obtener dicha cuenta.

### Crear cuenta en Ubuntu One

Nos dirigimos a la [página de login de Ubuntu](https://login.ubuntu.com/) y
seleccionamos "I don’t have an Ubuntu One account" y seguimos los pasos para su
creación.

![Creación de cuenta](images/instalación_ubuntu_rt/ubuntu_one.png "Creación de cuenta"){ width=75% }


### Obtener Ubuntu Pro

Una vez ya hemos creado la cuenta, vamos al
[apartado de pro](https://ubuntu.com/pro/subscribe) en la propia pagina de
Ubuntu e iniciamos sesión si no se ha iniciado automáticamente. Una vez en ahí,
seleccionamos "Myself" y le damos a "Register".

![Ubuntu Pro](images/instalación_ubuntu_rt/ubuntu_pro.png "Ubuntu Pro"){ width=75% }

### Añadir el sistema a la cuenta

Dentro del apartado de ["Your subscriptions"](https://ubuntu.com/pro/dashboard)
se encuetra el `token` que necesitamos añadir a la máquina.

![Ubuntu token](images/instalación_ubuntu_rt/ubuntu_token.png "Ubuntu token"){ width=75% }

Con el siguiente comando lo añadimos a Ubuntu.

```bash
sudo pro attach {token}
```

Donde `{token}` es el token de activación previamente mencionado.

### Instalar el kernel realtime

Para poder instalar el kernel realtime de ubuntu se ha de:

Actualizar la lista de paquetes del sistema e instalar las herramientas profesionales de ubuntu.

```bash
sudo apt update && sudo apt install ubuntu-advantage-tools
```

Acceder el repositorio realtime de Ubuntu (necesita confirmación por
terminal).

```bash
sudo pro enable realtime-kernel --access-only
```

Instalar y activar el kernel realtime de ubuntu.

```bash
sudo apt install ubuntu-realtime -y
```

Tras esto, se debe reiniciar el ordenador

### Comprobar el kernel

Con el siguiente comando se puede comprobar el kernel y su información, debe
aparecer `PREEMPT_RT` en lugar de `PREEMPT_DYNAMIC`

```bash
uname -a
```


# RTHybrid
### Descargar dependencias

Las siguientes librerías son dependencias de RTHybrid:

- qtmultimedia5-dev
- qtbase5-dev
- qtchooser
- qt5-qmake
- qtbase5-dev-tools
- libxml2
- libxml2-dev

Se pueden instalar con el siguiente comando:

```bash
sudo apt install qtmultimedia5-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools libxml2 libxml2-dev -y
```


### Descargar drivers Comedi

Ejecutar los siguientes comandos para instalar los drivers de Comedi.

```bash
git clone https://github.com/Linux-Comedi/comedi.git
cd comedi
./autogen.sh
cd ..
sudo dkms add ./comedi
sudo depmod -a
sudo apt install libcomedi0 libcomedi-dev -y
```

### Descargar RTHybrid

[RTHybrid Github](https://github.com/GNB-UAM/RTHybrid)

Para ello, ejecutar los siguientes comandos:

```bash
git clone https://github.com/GNB-UAM/RTHybrid.git
cd RTHybrid
sudo sh compile.sh
```

## Benchmarks

[Benchmarks Github](https://github.com/RoyVII/Latency_tests)
