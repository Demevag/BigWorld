#!/bin/bash

venv_dir="venv"
python_alias="vpython"

# Check if venv directory exists
if  ! [ -d "$venv_dir" ]; then
    echo "Creating virtual environment..."

    # Create virtual environment
    python3 -m venv $venv_dir

    # Activate virtual environment
    source $venv_dir/bin/activate

    # Install dependencies
    pip install -r utils/setup/requirements.txt
    echo "Virtual environment created and dependencies installed."

    # Deactivate virtual environment
    deactivate
else
  echo "Python environment already set up"
fi

if ! [ -L "$python_alias" ]; then
  echo "Creating vpython symbolic link..."
  # Create symbolic link to Python executable inside virtual environment
  ln -s $venv_dir/bin/python3 $python_alias

  echo "vpython symbolic link created."
else
  echo "vpython symbolic link already exists."
fi

echo "Setting up finished."
