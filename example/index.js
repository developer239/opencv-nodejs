const addon = require('../index')

const point = new addon.Point(new addon.Point(10, 20))

console.log('x, y', point.getX(), point.getY())
