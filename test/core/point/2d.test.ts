import { Point } from '../../../index'

describe('[core] Point 2D', () => {
  describe('constructor', () => {
    it('initializes from numbers', () => {
      const point = new Point(10, 20)

      expect(point.x).toStrictEqual(10)
      expect(point.y).toStrictEqual(20)
    })

    it('initializes from Point instance', () => {
      const point = new Point(new Point(20, 30))

      expect(point.x).toStrictEqual(20)
      expect(point.y).toStrictEqual(30)
    })
  })
})
