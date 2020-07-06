cc = gcc
prom = search-cli
dpes = stats.h search.h base.h
obj = main.o stats.o search.o base.o

$(prom): $(obj)
	$(cc) -o $(prom) $(obj)

%.o: %.c $(deps)
	$(cc) -c $< -o $@

clean:
	rm -rf $(obj) $(prom)
