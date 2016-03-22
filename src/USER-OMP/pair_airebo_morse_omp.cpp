/* ----------------------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#include "pair_airebo_morse_omp.h"
#include "error.h"
#include "force.h"

using namespace LAMMPS_NS;

/* ---------------------------------------------------------------------- */

PairAIREBOMorseOMP::PairAIREBOMorseOMP(LAMMPS *lmp) : PairAIREBOOMP(lmp) {}

/* ----------------------------------------------------------------------
   global settings
------------------------------------------------------------------------- */

void PairAIREBOMorseOMP::settings(int narg, char **arg)
{
  if (narg != 1 && narg != 3) error->all(FLERR,"Illegal pair_style command");

  cutlj = force->numeric(FLERR,arg[0]);

  if (narg == 3) {
    ljflag = force->inumeric(FLERR,arg[1]);
    torflag = force->inumeric(FLERR,arg[2]);
  }

  morseflag = 1;
}
