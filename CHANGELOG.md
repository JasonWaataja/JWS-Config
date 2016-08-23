#Change Log
This project adheres to Semantic Versioning.

## [Unreleased]
### Changed
- Store a reference to the current file so that opening and saving set that file
instead of always writing to ~/.jws.

### Fixed
- Now sorts subdirectories alphabetically.

### Added
- Add new mode feature. Check the JWS documentation for more info. It is now
able to use feh's various modes for setting the wallpaper which will make it
display differently and now has a gui tool to select it.

## [1.1.0] - 2016-08-15
### Added
- Finally added an icon!
- Can now open a file from the command line to load settings from.

### Changed
- Improve the about dialog.

## [1.0.1] - 2016-08-14
### Fixed
- Fix bug where randomize-order would be always be written to file instead of
in-order if the box was checked.
- Added shebang to autogen so it works now. I don't know how it did work
before.

### Changed
- Updated to use new time format with config files and also gives better
error messages.
- Now has a default windows size so it works better outside of i3

## [1.0] - 2016-08-12
### Added
- Initial release, development has been done in other repositories until now.
