int	rgb2hex(int r, int g, int b) 
{
    return (((1 << 24) + (r << 16) + (g << 8) + b));
}
__kernel void	julia(__global int *data, int X_WIN, int Y_WIN, double moveX, double moveY, double zoom, int maxIter, double Ju_cRe, double Ju_cIm, int r, int g, int b)
{
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	int		x = get_global_id(0);
	int		y = get_global_id(1);
	
	newRe = 1.5 * (x - X_WIN / 2) / (0.5 * zoom * X_WIN) + moveX;
	newIm = (y - Y_WIN / 2) / (0.5 * zoom * Y_WIN) + moveY;

	int i;
	
	i = -1;
	while (++i < maxIter)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + Ju_cRe;
		newIm = 2 * oldRe * oldIm + Ju_cIm;
		if ((newRe * newRe + newIm * newIm) > 4) break;
	}
	data[X_WIN * y + x] = rgb2hex(((i * r) % 255), ((i * g) % 255), ((i * b) % 255));
}

__kernel void	mandelbrot(__global int *data, int X_WIN, int Y_WIN, double moveX, double moveY, double zoom, int maxIter, double Ju_cRe, double Ju_cIm, int r, int g, int b)
{
	double		cRe;
	double		cIm;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	int		x = get_global_id(0);
	int		y = get_global_id(1);

	cRe = 1.5 * (x - X_WIN / 2) / (0.5 * zoom * X_WIN) + moveX;
	cIm = (y - Y_WIN / 2) / (0.5 * zoom * Y_WIN) + moveY;

	int i;

	newRe = 0;
	newIm = 0;
	i = -1;	
	while (++i < maxIter)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + cRe;
		newIm = 2 * oldRe * oldIm + cIm;
		if ((newRe * newRe + newIm * newIm) > 4) break;
	}
	if (i < maxIter)
		data[X_WIN * y + x] = rgb2hex(((i * r) % 255), ((i * g) % 255), ((i * b) % 255));
	else
		data[X_WIN * y + x] = 0;
				
}

__kernel void	pyramide(__global int *data, int X_WIN, int Y_WIN, double moveX, double moveY, double zoom, int maxIter, double Ju_cRe, double Ju_cIm, int r, int g, int b)
{
	double		cRe;
	double		cIm;
	double		zRe;
	double		zIm;
	double		tmp;
	int		x = get_global_id(0);
	int		y = get_global_id(1);

	
	cRe = -0.70176;
	cIm = -0.3842;
	zRe = 1.5 * (x - X_WIN / 2) / (0.5 * zoom * X_WIN) + moveX;
	zIm = 1.5 * (y - Y_WIN / 2) / (0.5 * zoom * Y_WIN) + moveY;

	int i;

	i = -1;	
	while (++i < maxIter)
	{
		tmp = zRe * zRe - zIm * zIm;
		zIm = 2 * zRe * zRe + cIm;
		zRe = tmp + cRe;
		if ((zRe * zRe + zIm * zIm) > 4) break;
	}
	data[X_WIN * y + x] = rgb2hex(((i * r) % 255), ((i * g) % 255), ((i * b) % 255));
}

__kernel void	puddle(__global int *data, int X_WIN, int Y_WIN, double moveX, double moveY, double zoom, int maxIter, double Ju_cRe, double Ju_cIm, int r, int g, int b)
{
	double		cRe;
	double		cIm;
	double		zRe;
	double		zIm;
	int		x = get_global_id(0);
	int		y = get_global_id(1);

	
	cRe = -0.70176;
	cIm = -0.3842;
	zRe = 1.5 * (x - X_WIN / 2) / (0.5 * zoom * X_WIN) + moveX;
	zIm = 1.5 * (y - Y_WIN / 2) / (0.5 * zoom * Y_WIN) + moveY;

	int i;

	i = -1;	
	while (++i < maxIter)
	{
		zRe = zRe * zRe - zIm * zIm + cRe;
		zIm = 2 * zRe * zIm + cIm;
		if ((zRe * zRe + zIm * zIm) > 4) break;
	}
	if (i < maxIter)
		data[X_WIN * y + x] = rgb2hex(((i * r) % 255), ((i * g) % 255), ((i * b) % 255));
	else
		data[X_WIN * y + x] = 0;
}

__kernel void	time_machine(__global int *data, int X_WIN, int Y_WIN, double moveX, double moveY, double zoom, int maxIter, double Ju_cRe, double Ju_cIm, int r, int g, int b)
{
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	int		x = get_global_id(0);
	int		y = get_global_id(1);
	
	newRe = 1.5 * (x - X_WIN / 2) / (0.5 * zoom * X_WIN) + moveX;
	newIm = 1.5 * (y - Y_WIN / 2) / (0.5 * zoom * Y_WIN) + moveY;

	int i;
	
	i = -1;
	while (++i < maxIter)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = cos(oldRe * oldRe) - sin(oldIm * oldIm) + Ju_cRe;
		newIm = 2 * oldRe * oldIm + Ju_cIm;
		if ((newRe * newRe + newIm * newIm) > 4) break;
	}
		data[X_WIN * y + x] = rgb2hex(((i * r) % 255), ((i * g) % 255), ((i * b) % 255));
}

__kernel void	bracelet(__global int *data, int X_WIN, int Y_WIN, double moveX, double moveY, double zoom, int maxIter, double Ju_cRe, double Ju_cIm, int r, int g, int b)
{
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	int		x = get_global_id(0);
	int		y = get_global_id(1);
	
	newRe = 1.5 * (x - X_WIN / 2) / (0.5 * zoom * X_WIN) + moveX;
	newIm = (y - Y_WIN / 2) / (0.5 * zoom * Y_WIN) + moveY;

	int i;
	
	i = -1;
	while (++i < maxIter)
	{
		oldRe = cos(newRe);
		oldIm = cos(newIm);
		newRe = oldRe * oldRe - oldIm * oldIm + Ju_cRe;
		newIm = 2 * oldRe * oldIm + Ju_cIm;
		if ((newRe * newRe + newIm * newIm) > 4) break;
	}
		if (i < maxIter)
		data[X_WIN * y + x] = rgb2hex(((i * r) % 255), ((i * g) % 255), ((i * b) % 255));
	else
		data[X_WIN * y + x] = 0;
}

__kernel void	butterfly(__global int *data, int X_WIN, int Y_WIN, double moveX, double moveY, double zoom, int maxIter, double Ju_cRe, double Ju_cIm, int r, int g, int b)
{
	double		cRe;
	double		cIm;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	int		x = get_global_id(0);
	int		y = get_global_id(1);

	cRe = 1.5 * (x - X_WIN / 2) / (0.5 * zoom * X_WIN) + moveX;
	cIm = (y - Y_WIN / 2) / (0.5 * zoom * Y_WIN) + moveY;

	int i;

	newRe = 0;
	newIm = 0;
	i = -1;	
	while (++i < maxIter)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = sin(oldRe) * cos(oldRe) - oldIm * oldIm + cRe;
		newIm = 2 * oldRe * oldIm + cIm;
		if ((newRe * newRe + newIm * newIm) > 4) break;
	}
		data[X_WIN * y + x] = rgb2hex(((i * r) % 255), ((i * g) % 255), ((i * b) % 255));
				
}


__kernel void	spider(__global int *data, int X_WIN, int Y_WIN, double moveX, double moveY, double zoom, int maxIter, double Ju_cRe, double Ju_cIm, int r, int g, int b)
{
	double		cRe;
	double		cIm;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	int		x = get_global_id(0);
	int		y = get_global_id(1);

	cRe = 1.5 * (x - X_WIN / 2) / (0.5 * zoom * X_WIN) + moveX;
	cIm = (y - Y_WIN / 2) / (0.5 * zoom * Y_WIN) + moveY;

	int i;

	newRe = 0;
	newIm = 0;
	i = -1;	
	while (++i < maxIter)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + cRe;
		newIm = 2 * oldRe * oldIm + cIm;
		cIm = cIm / 2 + newIm;
		cRe = cRe / 2 + newRe;
		if ((newRe * newRe + newIm * newIm) > 4) break;
	}
	if (i < maxIter)
		data[X_WIN * y + x] = rgb2hex(((i * r) % 255), ((i * g) % 255), ((i * b) % 255));
	else
		data[X_WIN * y + x] = 0;
				
}
