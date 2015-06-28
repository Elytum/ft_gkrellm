#include "../includes/MLXWindow.hpp"
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

int			MLXWindow::getSeenWidth() const {return (SCREEN_WIDTH / 10);}
int			MLXWindow::getSeenHeight() const {return (SCREEN_HEIGHT / 10);}
void		MLXWindow::open( void )
{

	mlx = mlx_init();
	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
}
void		MLXWindow::close( void )
{
	mlx_destroy_window(mlx, win);
}
void		MLXWindow::clr( void ) const
{
	mlx_clear_window(mlx, win);
}
void		MLXWindow::print( int x, int y, char const *c ) const
{
	char *cc = const_cast<char*>(c);
	mlx_string_put(mlx, win, x * 10, y * 10, 0xFFFFFF, cc);
}
void		MLXWindow::print( int x, int y, char c ) const
{
	char	str[1];
	str[0] = c;
	mlx_string_put(mlx, win, x * 10, y * 10, 0xFFFFFF, &c);
}
void		MLXWindow::print( int x, int y, char const *c, char const color ) const
{
	(void)color;
	char *cc = const_cast<char*>(c);
	mlx_string_put(mlx, win, x * 10, y * 10, 0xFFFFFF, cc);
}
void		MLXWindow::print( int x, int y, char const c, char const color ) const
{
	(void)color;
	char	str[1];
	str[0] = c;
	mlx_string_put(mlx, win, x * 10, y * 10, 0xFFFFFF, str);
}
void		MLXWindow::doPrint( int x, int y, char const *c, colorsKind color ) const
{
	(void)color;
	char *cc = const_cast<char*>(c);
	mlx_string_put(mlx, win, x * 10, y * 10, 0xFFFFFF, cc);
}
void		MLXWindow::printBox(int x, int y, int w, int h) const 
{
	x *= 10;
	y *= 10;
	w = x + w * 10;
	h = y + h * 10;
	for (int i = x; i < w; i++)
	{
		mlx_pixel_put(mlx, win, i, y, 0xFFFFFF);
		mlx_pixel_put(mlx, win, i, h, 0xFFFFFF);
	}
	for (int i = y; i < h; i++)
	{
		mlx_pixel_put(mlx, win, x, i, 0xFFFFFF);
		mlx_pixel_put(mlx, win, w, i, 0xFFFFFF);
	}
}
void		MLXWindow::printHLine(int x, int y, int w) const
{
	w += x;
	for (int i = x; i < w; i++)
		mlx_pixel_put(mlx, win, i, y, 0xFFFFFF);
}
void		MLXWindow::flush( void )
{

}
void		MLXWindow::addModule( MonitorModule * module, int row )
{
	modules[row].addModule(module);
}
void		MLXWindow::refresh( void )
{
	int	i = modules.size();
	int p = 0;
	int posX = 0;

	while (p < i) {
		modules[p].draw(posX, 0, *this);
		posX += modules[p].getWidth();
		++p;
	}
}