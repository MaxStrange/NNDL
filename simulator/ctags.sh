echo "Building ctags..."
ctags -R
echo "Building cscope..."
cscope -b -q -k -R
