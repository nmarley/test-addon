const testAddon = require('./build/Release/testaddon.node');
console.log('addon',testAddon);
console.log(testAddon.hello());
console.log(testAddon.add(9, 5));
module.exports = testAddon;
