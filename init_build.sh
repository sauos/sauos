#!/bin/sh

echo "Creating symlinks for directories. Please wait..."

set +e
ln -s ./cpus/$1 core/arch
ln -s ./cpus/$1/include include/arch
ln -s ./cpus/$1/servers servers/arch-servers

echo "Created symlinks. Run make now."
