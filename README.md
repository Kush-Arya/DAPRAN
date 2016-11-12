# DAPRAN
DAta PRocessing &amp; ANalytics

Author : Nidish Narayanaa B.

Email : nidbid@gmail.com

DAPRAN, DAta PRocessing &amp; ANalytics is my attempts at delivering a package which can enable scientists and engineers to do 
data analysis from the linux command line with basic pipelines. The idea is to reduce the dependence on actual software for 
such calculations while enabling the user to work in the comfort of the shell command line interface itself. The target users
engineers and scientists working in the field of Digital Signal Processing, Dynamical Systems, etc.

I have started off with an FFT/IFFT program using FFTW3 as of now. I will be moving into STFT, filters, and other Signal processing features in the coming days.
I will be adding binaries as and when I write them.

Binaries:

1) nidfft - conducts fft and ifft on data from file or pipe

2) nidstft - conducts stft on data from file or pipe - a few standard window functions have been implemented

3) wavegen - generates a sum of sinusoids

4) convolve - A basic convolution tool

5) nidpoincare - takes the poincare section of an arbitrary dimensional data

Any help from anybody anywhere is welcome - in the form of adding more codes, helping with packaging (Make), etc.
