#!/usr/bin/bash

cat 01_seastar_header.urdf > seastar.urdf.xacro
cat 02_seastar_imulink.urdf >> seastar.urdf.xacro

cat 03_seastar_base.urdf.xacro >> seastar.urdf.xacro
cat 04_seastar_upright1.urdf.xacro >> seastar.urdf.xacro
cat 05_seastar_roll.urdf.xacro >> seastar.urdf.xacro
cat 06_seastar_pitch.urdf.xacro >> seastar.urdf.xacro
cat 07_seastar_stokes.urdf.xacro >> seastar.urdf.xacro

cat 08_seastar_footer.urdf >> seastar.urdf.xacro

xacro seastar.urdf.xacro > seastar.urdf



