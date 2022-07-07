#!/bin/bash

for file in libft/*.c; do
  vim -c "Stdheader" -c wq $file
done

for file in libft/*.h; do
  vim -c "Stdheader" -c wq $file
done