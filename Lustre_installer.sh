#!/bin/bash

# Download the file
wget https://www-verimag.imag.fr/DIST-TOOLS/SYNCHRONE/lustre-v6/pre-compiled/$(arch)-$(uname)-lv6-bin-dist.tgz

# Extract the downloaded tar.gz file
tar xvfz "$(arch)-$(uname)-lv6-bin-dist.tgz"

# Remove the .tgz file after extraction
rm "$(arch)-$(uname)-lv6-bin-dist.tgz"

# Path to the script you want to modify
TARGET_SCRIPT="v6-tools.sh"

# Old code that needs to be replaced
old_text=$(cat <<EOF
if test -z "\$LV6_PATH" ; then
  LV6_PATH=\$(pwd)
fi
EOF
)

# New code to replace the old code
new_text=$(cat <<EOF
# Get the directory where this script is located
SCRIPT_DIR="\$(cd "\$(dirname "\${BASH_SOURCE[0]}")" && pwd)"

# Set LV6_PATH to lv6-bin-dist inside the same directory as the script
LV6_PATH="\$SCRIPT_DIR/lv6-bin-dist"

# Ensure the directory exists (optional)
if [ ! -d "\$LV6_PATH" ]; then
  echo "Warning: \$LV6_PATH does not exist!"
fi
EOF
)

# Use sed to replace the block of code
sed -i '/if test -z "\$LV6_PATH" ; then/,/fi/c\
# Get the directory where this script is located\
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"\
\
# Set LV6_PATH to lv6-bin-dist inside the same directory as the script\
LV6_PATH="$SCRIPT_DIR/lv6-bin-dist"\
\
# Ensure the directory exists (optional)\
if [ ! -d "$LV6_PATH" ]; then\
  echo "Warning: $LV6_PATH does not exist!"\
fi' "$TARGET_SCRIPT"
