README for rho.c
Puyan Lotfi
Math 3012: Ravi Montenegro

The tarball can be found at: 

http://www.asbestosis.ath.cx/~puyan/rho.tar.gz

or

http://www.cc.gatech.edu/~puyan/rho.tar.gz


- To compile rho.c just "make".
- If you want to see the prompt
  that comes up when running
  "make prompt".
- To run, enter "./rho.bin n"
  or "./rho.bin n c x_0", entering
  just n is the same entering 
  "./rho.bin n 1 2". 
- For debug output "make debug".


The random 10 were a result of me pecking
randomly at the numpad until I had 90 digits
then I just made newlines and got rid of 
the leading zeros.

The next 2 sets (products of primes) were
just a result of me randomly picking 
primes from the list provided.

10 random 9 digit numbers:

   n           Steps    Factor

135824683        4       23
579985629        1        3
560702715        1        3 
957290567        4       23
252106708        1        7
290672595        1        3
179593002        1        3 
890509820        2        4
658295002        2        2
800592905        1        7

average number of steps:  2 (1.8 was the mean)

10 9 digits number which are the 
product of 3 3-4 digit primes:

    n             primes             Steps      Factor

343775741 =   883 *  617 *  631        26         631        
191362879 =  1031 *  313 *  593         5         313 
709666267 =   769 *  911 * 1013        17      922843 *
587050549 =   983 *  599 *  997         9         983
414973483 =  1039 *  347 * 1151        16        1151
723192959 =  1201 *  701 *  859        20         701
401919487 =   587 * 1039 *  659        22         659
513379333 =   967 *  521 * 1019        16        1019
866938019 =  1033 *  977 *  859         9        1033
504731189 =   563 * 1051 *  853         5         563

average number of steps: 

                           mean: 92989.60
            without the outliers:   784    (783.66 mean)
          911 instead of 922843:   796    (796.40 mean)

* note: These are the same result as rho.exe (Red Hat) 
        which was posted on the project website. I 
        actually found another implementation which
        I planned on using for testing my results along
        which rho.exe that gave me different factors.
        For example for the noted n, I got the factor
        911. I am not too sure why at this moment, but
        my results are in line with the posted rho.exe
        so I will leave it be. The site with the other 
        implementation is 

http://www.math.umbc.edu/~campbell/NumbThy/Class/
Programming/JavaScript.html

IN NO WAY WAS THIS IMPLEMENTATION USED FOR THE MAKING 
OF THIS PROGRAM!!! 


10 9 digit numbers which are the 
product of 2 4-5 digit primes:

    n          primes          Steps         Factor

140946259 = 12253 * 11503        19           12253 
112684927 =  9973 * 11299       150           11299
114433733 = 11161 * 10253        39           11161
111110557 = 11177 *  9941       125           11177
122167139 = 11393 * 10723        77           10723
120095057 = 10891 * 11027       168           10891
134424203 = 11897 * 11299       150           11299
131215319 = 11119 * 11801        94           11119
131053679 = 11503 * 11393        40           11503
141214349 = 12421 * 11369        70           11369

average number of steps: 93 (93.2 mean)


Most of the cases I tried, the number of steps was smaller than 
1.2 * sqrt(p) (even the smaller factor). For example
1.2*sqrt(631) = ~30 and the number of steps was 26. Usually
it would be close to a smaller factor p, but less.

For 244109835389118539 Brent's Rho doesn't seem too much quicker 
that Pollard's Rho on the Redhat machine hensinki (coc machine, 
dual P4 Xeons) at first run. But timing them you see:

helsinki% time ./brentrho.exe 244109835389118539 1 2
It took 12664 steps to find a factor.
Required 0.17000 seconds.
A factor of 244109835389118539 is 44680463.
0.170u 0.000s 0:00.17 100.0%    0+0k 0+0io 216pf+0w
helsinki% time ./rho.exe 244109835389118539 1 2
It took 8944 steps to find a factor.
Required 0.29000 seconds.
A factor of 244109835389118539 is 44680463.
0.290u 0.000s 0:00.30 96.6%     0+0k 0+0io 216pf+0w
helsinki%

So now we see that Brent's Rho is nearly twice as fast as 
Pollard's Rho. 





