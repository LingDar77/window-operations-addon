{
  "targets": [
    {
      "target_name": "windowOperation",
      "sources": [ "./src/windowOperation.cc" ],
      "include_dirs": ["<!(node -e \"require('nan')\")" ]
    }
  ]
}
