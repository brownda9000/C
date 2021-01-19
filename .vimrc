nmap =j :%!python -m json.tool<CR>
function! FormatJSON()
:%!python -m json.tool
endfunction

set shiftwidth=4 tabstop=4   autoindent smartindent
set cursorline
set rnu
set nu rnu
set incsearch  ignorecase  smartcase  hlsearch
set updatecount=10
set colorcolumn=80
set ruler
set filetype=on
syntax on

" Make naughty characters visible...
" (uBB is right double angle, uB7 is middle dot)
set lcs=tab:»·,trail:␣,nbsp:˷
highlight InvisibleSpaces ctermfg=Black ctermbg=Black
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" " alternatively, pass a path where Vundle should install plugins
call vundle#begin()
"
" " let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
"
"Plugin 'sjl/badwolf'
"Plugin 'yegappan/taglist'
"Plugin 'frazrepo/vim-rainbow'
"au FileType c,cpp,objc,objcpp call rainbow#load()
" " All of your Plugins must be added before the following line
call vundle#end()            " required
"filetype plugin indent on    " required
" " To ignore plugin indent changes, instead use:
" "filetype plugin on
" "
" " Brief help
" " :PluginList       - lists configured plugins
" " :PluginInstall    - installs plugins; append `!` to update or just
" :PluginUpdate
" " :PluginSearch foo - searches for foo; append `!` to refresh local cache
" " :PluginClean      - confirms removal of unused plugins; append `!` to
" auto-approve removal
" "
" " see :h vundle for more details or wiki for FAQ
" " Put your non-Plugin stuff after this line
nnoremap g^ gUiW
nnoremap gv guiW
augroup VimReload
autocmd!
autocmd BufWritePost $MYVIMRC source $MYVIMRC
augroup END
