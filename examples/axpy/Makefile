build:
	g++ axpy.cpp -pg -g -o axpy-pg
	g++ axpy.cpp -g -o axpy

docs:
	doxygen Doxyfile

clean:
	rm -rf a.out axpy axpy-pg

gprof-cg:
	./axpy-pg 1024
	gprof axpy-pg | gprof2dot >axpy-gprof-cg.dot

perf-cg:
	perf record -g -- ./axpy 1024
	perf script | c++filt | gprof2dot -f perf >axpy-perf-cg.dot

distclean: clean
	rm -rf docs
