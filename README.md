![Fractol](https://github.com/user-attachments/assets/9e41d13b-a509-41db-aee6-234a499c02b6)
# Fract’ol

A real-time fractal viewer built in C using MiniLibX.

## Overview

This program lets you explore **Mandelbrot** and **Julia** fractals with smooth zooming capabilities. Use the mouse wheel to zoom and experiment with different Julia fractal parameters via the command line.

## Features

- **Fractals**: Mandelbrot and Julia sets by default  
- **Zoom**: Smooth, continuous via mouse wheel  
- **Custom Julia**: Pass custom parameters for unique renders  
- **Colorful visuals**: Multi-color mapping for depth perception  
- **Stable UI**: Clean exit with ESC or window close, handles redraws robustly  

## Bonus Features

- **Extra fractal**: Add your own favorite fractal (e.g. Burning Ship)  
- **Zoom follows cursor**: Zoom center tracks mouse pointer

## Usage

```bash
git clone https://github.com/monsieurCanard/Fract-ol
cd fractol
make          # Builds mandatory part
./fractol mandelbrot
./fractol julia
make bonus
./fractol burning_ship
