#ifndef MLXWINDOW_HPP
# define MLXWINDOW_HPP
# include <ModuleRow.hpp>
# include <MonitorModule.hpp>
# include <IMonitorDisplay.hpp>
# include <Config.hpp>
# include <mlx.h>


class MLXWindow : public IMonitorDisplay
{
public:
	MLXWindow();
	virtual ~MLXWindow();

	virtual int			getSeenWidth() const;
	virtual int			getSeenHeight() const;
	virtual void		open( void );
	virtual void		close( void );
	virtual void		clr( void ) const;
	virtual void		print( int x, int y, char const *c ) const;
	virtual void		print( int x, int y, char const c ) const;
	virtual void		print( int x, int y, char const *c, char const color ) const;
	virtual void		print( int x, int y, char const c, char const color ) const;
	virtual void		doPrint( int x, int y, char const *c, colorsKind color ) const;
	virtual void		printBox(int x, int y, int w, int h) const;
	virtual void		printHLine(int x, int y, int w) const;
	virtual void		flush( void );
	virtual void		addModule( MonitorModule * module, int row );
	virtual void		refresh( void );

private:
	bool						opened;
	std::vector<ModuleRow>		modules;

	void		*mlx;
	void		*win;
	int			height;
	int			width;
	
};

#endif