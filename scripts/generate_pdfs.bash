#!/bin/bash

if [ ! -d "tuts_and_reports/markdown" ]; then
  echo "Please run this script from the parent directory of docs/ (e.g., project root)."
  exit 1
fi

MARKDOWN_DIR="tuts_and_reports/markdown"

for md_file in "$MARKDOWN_DIR"/*.md; do
  filename=$(basename "$md_file" .md)

  (
    echo "generating $filename.pdf"
    cd "$MARKDOWN_DIR" || exit
    pandoc "$filename.md" \
      -f markdown --listings \
      -H config/listings-setup.tex \
      -V geometry:"left=1cm, top=1cm, right=1cm, bottom=2cm" \
      -V fontsize=12pt \
      -V urlcolor='blue' \
      -V block-headings \
      -o "../$filename.pdf"
  )
done
