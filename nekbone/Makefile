timeit: timeit.f axi.f local_grad3.f local_grad3_t.f mxm.f add2.f
	gfortran -cpp -DNUMGP=10 -DNUMEL=7040 -O3 -o timeit timeit.f axi.f local_grad3.f local_grad3_t.f mxm.f add2.f 

timeit_all: timeit.f axi_all.f local_flat_all.f
	gfortran -cpp -DNUMGP=10 -DNUMEL=7040 -O3 -o timeit_all timeit.f axi_all.f local_flat_all.f 

timeit_all16: timeit.f axi_all16.f local_flat_all16.f
	gfortran -cpp -DNUMGP=10 -DNUMEL=7040 -O3 -o timeit_all16 timeit.f axi_all16.f local_flat_all16.f 

compare: compare_new.f local_grad3.f local_grad3_t.f mxm.f add2.f local_flat_all.f local_flat_all16.f local_flat_t.f local_flat.f local_flat16.f
	gfortran -cpp -DNUMGP=10 -DNUMEL=7040 -O3 -o compare compare_new.f local_grad3.f local_grad3_t.f mxm.f add2.f local_flat_all.f local_flat_all16.f local_flat_t.f local_flat.f local_flat16.f

clean:
	rm -f timeit timeit_all timeit_all16 compare
