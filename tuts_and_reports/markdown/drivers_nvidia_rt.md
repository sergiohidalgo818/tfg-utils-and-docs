# Fixing Nvidia drivers for RT kernel


## Removing all previous drivers

This includes noveau drivers, we need to do this for preventing confilcts with later installation.

```bash
sudo apt purge "*nvidia*"
sudo bash -c 'echo "blacklist nouveau" >> /etc/modprobe.d/blacklist.conf'
```

## Kernel headers

Install headers for your kernel.

```bash
sudo apt install linux-headers-$(uname -r)
```

## Extra tools

You are going to recompile the drivers (by executing nvidia's program, dont be scared) so you will need the build-essential package.

```bash
sudo apt-get install build-essential
```

## Dowload the drivers

Go to [nvidia official page](https://www.nvidia.com/en-us/drivers/) (I know it hurts) and download the drivers for your GPU and system.

## Install the drivers

### Before installing

You will need to deactivate your GUI, I use GNOME so I will stop gdm service (GNOME Display Manager).

```bash
sudo systemctl stop gdm
```

### Executing the installer

You will need to tell the installer to ignore the presence of the RT system, otherwise it won't work.

```bash
sudo IGNORE_PREEMPT_RT_PRESENCE=1 bash NVIDIA-Linux-x86_64-570.144.run 
```


### Maximum performance

If you are having issues with GNOME animations, go to *NVIDIA X Server Settings* and under "PowerMizer", set "Preferred Mode" to "Prefer Maximum Performance" 
