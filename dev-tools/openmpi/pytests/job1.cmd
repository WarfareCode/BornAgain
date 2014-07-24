#!/bin/bash
#
#@ job_type = parallel
#@ class = test
#@ node = 2
##@ total_tasks=8
#@ tasks_per_node = 4
#@ island_count=1
#@ wall_clock_limit = 0:20:00
#@ job_name = mytest
#@ network.MPI = sn_all,not_shared,us
#@ initialdir = $(home)/jobs
#@ output = job$(jobid).out
#@ error = job$(jobid).err
#@ notification=always
#@ notify_user=guennadi.pospelov@gmail.com
##@ energy_policy_tag = BornAgainEnergyTag
##@ minimize_time_to_solution = yes
#@ queue
. /etc/profile
. /etc/profile.d/modules.sh
export MP_SINGLE_THREAD=no
export OMP_NUM_THREADS=4
export MP_TASK_AFFINITY=core:$OMP_NUM_THREADS
module load python/2.7_anaconda
module load fftw/mpi/3.3
module load gsl
export LD_LIBRARY_PATH=/home/hpc/pr87me/di29sok/software/boost_1_55_0.gcc47/lib:/home/hpc/pr87me/di29sok/development/BornAgain/installed/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/hpc/pr87me/di29sok/development/BornAgain/installed/lib:$PYTHONPATH
poe python ompi_meso_cpp.py
